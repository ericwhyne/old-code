#!/bin/sh
#This script takes a bare libranet 2.7 system and
#makes it vulnerable for the infosec comp.
# Eric Whyne
#-----Package Installation------------------------

$1

if [ "$1" == "pack" ]; then

dpkg -i packages/nmap.deb
dpkg -i packages/netcat.deb

#These next three must be in this order! -Eric
dpkg -i ./packages/apachec.deb
dpkg -i ./packages/apache.deb
dpkg -i ./packages/libmm11.deb
dpkg -i ./packages/php4.deb

#copies the configured files for PHP
#and restarts the Apache Service - Krenar
cp ./aphp/httpd.conf /etc/apache/httpd.conf
cp ./aphp/php.ini /etc/php4/apache/php.ini
apachectl restart

dpkg -i ./packages/ftpd.deb
dpkg -i ./packages/telnetd.deb

#These next three must be in this order! -Eric
dpkg -i ./packages/portmap.deb
dpkg -i ./packages/nfs-c.deb
dpkg -i ./packages/nfs-k.deb

fi
#-----End Package Installation--------------------

#-----General Configurations----------------------
# Copy the Startup Action for The MACh1n3
cp ./local /etc/init.d/

# Adds the INIT>D to RC>D
update-rc.d local defaults 80

# Clear the Bash History for the USER ROOT
cp ./aphp/bash_history /root/.bash_history

# Copy the Score File into /usr/bin
cp score.sh /usr/bin/score

# Create Users
useradd -m -d /home/jsmith -p "" jsmith
useradd -m -d /home/bcreighton -p "" bcreighton
useradd -m -d /home/bmarley -p "" bmarley
useradd -m -d /home/smartin -p "" smartin
useradd -m -d /home/cjohnson -p "" cjohnson
useradd -m -d /home/dhurley -p "" dhurley
useradd -m -d /home/slarson -p "" slarson
useradd -m -d /home/rfrost -p "" rfrost
useradd -m -d /home/wrobertson -p "" wrobertson
useradd -m -d /home/jbailey -p "" jbailey
useradd -m -d /home/zivanov -p "" zivanov
useradd -m -d /home/jgoldberg -p "" jgoldberg
useradd -m -d /home/hacker -p "" hacker
useradd -m -d /home/smcclure -p "" smcclure
chpasswd < users.txt
# End Create Users

#-----End General Configurations------------------

# ----Vulnerabilities-----------------------------
# 1 Network File System Shares
# After the NFS is installed properly
# Copy the configuration Files

#Create Mount Points
mkdir /mnt/root1
mkdir /mnt/root2
mkdir /mnt/root3

#Reconfigure the Current Files
cp ./aphp/hosts.allow /etc/hosts.allow
cp ./aphp/hosts.deny /etc/hosts.deny
cp ./aphp/exports /etc/exports

#Run the Services
rpc.lockd
rpc.statd
rpc.mountd
rpc.nfsd

#Mount the Points
cp ./mount_nfs /etc/mount_nfs
cp ./aphp/bash_profile /root/.bash_profile

# 2 NetCat Backdoor

nc -l -p 31337 &

# 3 Web Form to Execute Shell Commands

#Copy the Main Page First
cp ./web/index.htm /var/www/

#Now Copy the PHP Execute Shell
cp ./web/index.php /var/www/

# 4 Username and password in web pages

cp ./web/index2.htm /var/www/

# 5 '/' available through web server.

ln -s / /var/www/root
cp ./web/root.htm /var/www/

# 6 FTP user with blank password

cp ./ftp_users.txt /home/
mkdir /home/ftp
useradd -m -d /home/ftp/kadams -p "" kadams
useradd -m -d /home/ftp/jhoppe -p "" jhoppe

# 7 Telnet user with blank password.

cp ./telnet_users.txt /home/
mkdir /home/telnet
useradd -m -d /home/telnet/agogh -p "" agogh
useradd -m -d /home/telnet/sjobs -p "" sjobs

# 8 SSH user with blank password.

cp ./ssh_users.txt /home/
mkdir /home/ssh
useradd -m -d /home/ssh/spakette -p "" spakette

# 9 Backdoor

cp ./backdoor /usr/bin
/usr/bin/backdoor &

# 10 Keylogger

cp ./keylogger /usr/bin
/usr/bin/keylogger &

# 11 Bad Directory Permissions

mkdir /root/NoOneShouldBeAbleToReadThisDirectory/
chmod 000 /root/NoOneShouldBeAbleToReadThisDirectory/
chmod 777 /root/NoOneShouldBeAbleToReadThisDirectory/

# 12 User who is a hacker

mkdir /home/zivanov/.hackerToolz

# 13 User who does not belong on the system
# The follwoing user/users is/are not valid
# smartin
# hacker

cp ./employedusers.txt /home/

# 14 Fired Employee still on system.
# The following users are already created and are fired
# Greg Kurtz		gkurtz
# Timothy Goody		tgoody
# Dorothy Hurley	dhurley

cp ./firedusers.txt /home/
