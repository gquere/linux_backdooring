Goals
=====

Goal for the attacker:

* leave a means to come back as root on the machine: remote backdoor
* leaves as little logs as possible

Goal for the defender:

* find out ASAP if a backdoor has been inserted


Assumptions:

* attacker is root
* attacker cannot stop protections already in place
* attacker cannot produce very advanced exploits (fake FS information, rootkit ...)


Kernel
======
Module
------
Add a module.

=> Sign kernel modules
=> Forbid module loading after boot

Kernel itself
-------------

=> Kernel signing?
=> Investigate unscheduled reboots
=> Control kernel integrity


Userspace remote backdoors
==========================
Standalone Process
------------------
Always listening for a remote connection, port knocking
Can be hidden from ps
Name can be hidden by overwriting argv[0]
Can be deleted after launch
Can be run from shell directly without touching disk
Replace binary

=> Need to scan /proc, not ps
=> check if symlink exe matches argv[0]


Standalone Process triggered by external packet
-----------------------------------------------
Command run on iptables TRIGGER
iptable module

=> Audit NF rules
=> forbid iptables modules


Standalone process triggered by application crash
-------------------------------------------------
Kernel crash handler core_pattern hookup

=> Monitor it?


Standalone process triggered by reboot
--------------------------------------
Somewhere in an init script

=> Monitor init scripts


Watching logs
-------------
``` bash
tail -F /var/log/syslog | awk '/Failed logging for user fhqsdghflhdsqk/ {system("run_backdoor")}'
```

=> Scan /proc


Triggered by crontab/at
-----------------------
Could be used to evade /proc/ scanning.

=> Need to control user and system jobs.


Inject into authorized process/library binary
---------------------------------------------
Add a backdoor to a binary.
Add a backdoor to a webserver.

=> Need to control binary integrity
=> Need to control directories


Inject into process memory
--------------------------
Is this even possible? Injecting SSHd?
Lost at reboot.
cymothoa?

Impossible to detect?


Hijack loader
-------------
Add configuration to /etc/ls.so.conf,/etc/ld.so.conf.d

=> Control integrity of configuration


PAM configuration
-----------------
Alter PAM configuration

=> Need to control configuration integrity


SSH configuration
-----------------
Add an authorized key
Default to another PAM

=> Centralize and monitor authorized keys


User hijacking
--------------
Add a user, or change a user's password.

=> Monitor /etc/{passwd,shadow}



Local backdoors
===============

Add root rights to low-privileged user
--------------------------------------
/etc/sudoers
/etc/sudoers.d/
/etc/passwd
/etc/groups

=> Monitor sudoers


Setuid/Setgid binary
--------------------

=> Monitor FS rights

Capabilities binary
-------------------
Use a capability to escalate to UID 0.

=> Monitor full FS rights
