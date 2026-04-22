# My Journey to the Kernel 🛠️

This repository serves as my dev-log while exploring low-level programming and Windows internals. The goal is to master kernel-mode development and understand how the OS works under the hood—without catching a BSOD every five minutes.

## 🛠️ What's Inside:

* **Windows-Kernel-Process-Monitor** 🛡️ – **My first real Driver!** Written in C using the Windows Driver Kit (WDK). It operates in **Ring 0** and monitors process creation/termination in real-time. It implements kernel callbacks (`PsSetCreateProcessNotifyRoutine`) and ensures safe `EPROCESS` object management.
* **polymorphism_generic.c** 🧩 – Advanced C concepts. A generic "driver template" using function pointers (callbacks) and `void*` to achieve polymorphic behavior in C.
* **malloc_float_test.c** 🧠 – My first encounter with manual memory management. Practicing `malloc` and `free` to ensure heap stability and avoid memory leaks.

---

## 📈 Roadmap:

1. **Bitwise Operations** – Mastering bit manipulation and system flags.
2. ~~**Dive into WDK** and write code that actually communicates with the kernel.~~ **[COMPLETED!]**
3. **Active Process Blocking** – Expanding the process monitor to implement an "Access Denied" feature for specific executables.
4. **IOCTL Communication** – Developing a User-mode application to send control codes and data directly to my driver.

> *Errors are just logs waiting to be fixed. A stable system is just a system I haven't managed to break yet.* 🚀
