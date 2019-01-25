Goals
=====

Goal for the red team:

* leave a means to come back as root on the machine: remote backdoor
* leaves as little logs as possible

Goal for the blue team:

* find out ASAP if a backdoor has been inserted


Assumptions:

* red team is root
* red team cannot stop protections already in place
* red team cannot produce very advanced exploits (fake FS information, rootkit ...)


Kernel
======
Module
------
Red team:

* Add a module.

Blue team:

* Sign kernel modules
* Forbid module loading after boot

Kernel itself
-------------

Blue team:

=> Kernel signing?
=> Investigate unscheduled reboots
=> Control kernel integrity


Userspace remote backdoors
==========================
Standalone Process
------------------
Red team:

* Always listening for a remote connection, port knocking
* Can be hidden from ps
* Name can be hidden by overwriting argv[0]
* Binary can be deleted after launch
* Can be run from shell directly without touching disk
* Replace binary

Blue team:
* Need to scan /proc, not ps
* check if symlink exe matches argv[0]


Standalone Process triggered by external packet
-----------------------------------------------
Red team:

* Command run on iptables TRIGGER
* iptable module

Blue team:

* Audit NF rules
* monitor/forbid iptables modules


Standalone process triggered by application crash
-------------------------------------------------
Red team:

* Kernel crash handler core_pattern hookup

Blue team:

* Monitor it?


Standalone process triggered by reboot
--------------------------------------
Red team:

* Somewhere in an init script

Blue team:

* Monitor/sign init scripts


Standalone process triggered by a log
-------------------------------------

``` bash
tail -F /var/log/syslog | awk '/Failed logging for user fhqsdghflhdsqk/ {system("run_backdoor")}'
```

Blue team:

* Scan /proc


Triggered by crontab/at
-----------------------

Red team:

* Could be used to evade /proc/ scanning.


Blue team:

* Need to control user and system jobs.


Inject into authorized process/library binary
---------------------------------------------

Red team:

* Add a backdoor to a binary.
* Add a backdoor to a webserver.

Blue team:

* Need to control binary integrity
* Need to control directories


Inject into process memory
--------------------------

Red team:

* inject backdoor into process memory
* Lost at reboot.

Blue team:

* Impossible to detect?


Hijack loader
-------------

Red team:

* Add configuration to /etc/ls.so.conf,/etc/ld.so.conf.d

Blue team :

* Control integrity of configuration


PAM configuration
-----------------
Red team:

* Alter PAM configuration

Blue team:

*  Need to control configuration integrity


SSH configuration
-----------------
Red team:

* Add an authorized key
* Default to another PAM

Blue team:

* Centralize and monitor authorized keys


User hijacking
--------------
Red team:

* Add a user, or change a user's password.

Blue team:
* Monitor /etc/{passwd,shadow}



Local backdoors
===============

Add root rights to low-privileged user
--------------------------------------
* /etc/sudoers
* /etc/sudoers.d/
* /etc/passwd
* /etc/groups

Blue team:

* Monitor sudoers


Setuid/Setgid binary
--------------------

=> Monitor FS rights

Capabilities binary
-------------------
Use a capability to escalate to UID 0.

=> Monitor full FS rights
