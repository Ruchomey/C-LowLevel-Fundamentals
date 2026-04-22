#include <ntifs.h>

NTKERNELAPI PCHAR PsGetProcessImageFileName(PEPROCESS Process);

void MyProcessNotifyRoutine(HANDLE ParentId, HANDLE ProcessId, BOOLEAN Create) {
	UNREFERENCED_PARAMETER(ParentId);

	if (Create) {
		
		PEPROCESS Process = NULL;
		NTSTATUS status = PsLookupProcessByProcessId(ProcessId, &Process);

		if (NT_SUCCESS(status)) {

			PCHAR name = PsGetProcessImageFileName(Process);
			DbgPrint("Opening program NAME: %s and PID: %d\n", name, (ULONG)(ULONG_PTR)ProcessId);
			ObDereferenceObject(Process);
		}
	}
	else {
		DbgPrint("Process Exiting: PID: %d\n",(ULONG)(ULONG_PTR)ProcessId);
	}
}

void UnloadMyDriver(PDRIVER_OBJECT DriverObject) {
	UNREFERENCED_PARAMETER(DriverObject);
	
	PsSetCreateProcessNotifyRoutine(MyProcessNotifyRoutine, TRUE);
	DbgPrint("LOG: Hey im unloading rn bye!\n");
}


NTSTATUS DriverEntry(PDRIVER_OBJECT DriverObject, PUNICODE_STRING RegistryPath) {
	UNREFERENCED_PARAMETER(RegistryPath);

	DbgPrint("LOG: Hey i have completed Driver Entry im in kernel now!\n");

	NTSTATUS status = PsSetCreateProcessNotifyRoutine(MyProcessNotifyRoutine, FALSE);

	if (!NT_SUCCESS(status)) {
		DbgPrint("LOG: Cos poszlo nie tak przy rejestracji callbacka :(\n");
		return status;
	}

	DriverObject->DriverUnload = UnloadMyDriver;

	return STATUS_SUCCESS;
}