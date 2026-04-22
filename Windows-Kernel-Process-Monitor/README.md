# Windows Kernel Process Monitor

## 📝 Overview
A lightweight Windows Kernel-mode driver that monitors process creation and termination across the system. This project was developed to explore **Kernel-mode programming**, system-wide notification mechanisms, and the internal architecture of the Windows operating system.

The driver utilizes **Kernel Notification Callbacks** to intercept process events in real-time.

## 🛠️ Key Concepts Learned
* **Kernel Callbacks:** Registering system-wide event listeners using `PsSetCreateProcessNotifyRoutine`.
* **Object Management:** Converting a `ProcessId` (HANDLE) into a full `EPROCESS` object pointer via `PsLookupProcessByProcessId`.
* **Reference Counting:** Managing the lifecycle of kernel objects using `ObDereferenceObject` to prevent memory leaks and system instability (BSOD).
* **Opaque Structures:** Retrieving process information from internal kernel structures using `PsGetProcessImageFileName`.
* **WDK Data Types:** Hands-on experience with kernel-specific types such as `PCHAR`, `NTSTATUS`, `PEPROCESS`, and `ULONG_PTR`.

## 🚀 How It Works
When a process starts or exits, the Windows Kernel executes the registered callback routine. The driver then:
1. Validates the event type (Creation vs. Termination).
2. Lookups the process object in memory.
3. Extracts the **Image File Name** and **PID**.
4. Dispatches the data to the system debug buffer.

### Sample Output (DebugView):

LOG: Hey i have completed Driver Entry im in kernel now!

Process Exiting: PID: 17052

Opening program NAME: dllhost.exe and PID: 5632



