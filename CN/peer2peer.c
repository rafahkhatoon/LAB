#!/bin/bash

echo "Network Configuration"
echo

echo "1. Operating System Information"
uname -a
echo

echo "2. Hostname"
hostname
echo

echo "3. Current Logged-in User"
whoami
echo

echo "4. Networking Interface Details"
ifconfig
echo

echo "5. Testing Network Connectivity"
read -p "Enter IP address or hostname to ping: " ip
ping -c 4 "$ip"
echo

echo "6. Change Password (Optional)"
read -p "Do you want to change your password? (y/n): " ans

if [ "$ans" = "y" ]; then
    passwd
fi

echo

echo "7. Transfer a File Using SFTP"
read -p "Enter username: " usy
read -p "Enter IP address: " host

echo "Connecting to $host"
sftp "$usy@$host"

echo "Inside SFTP you can use:"
echo "put filename - upload a file"
echo "get filename - download a file"
echo "bye - exit SFTP"

echo
echo "Configuration Completed"