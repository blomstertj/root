### BACKGROUND
Adding DNS servers to multiple devices can be a long process especially if you have hundreds of network devices.  Using Cisco Prime you can deploy any type of configuration to many devices quickly.

### HOW IT WORKS
One DNS server is required.
An additional server can be added.
The checkbox removes all DNS servers currently on the devices BEFORE applying the new server(s).

1. The CLI checks to see if the box was checked to remove all the current servers.  If checked, `no ip name-server` will be ran to remove current servers.
2. Then it applies the first DNS server using `ip name-server $dns_serv_1` where `$dns_serv_1` is an IPv4 address entered in the `DNS Server 1` box.
3. If an IPv4 address is present in the `DNS Server 2` box then it will run `ip name-server $dns_serv_2` where `$dns_serv_2` is the IPv4 address entered.  If there isn't anything in the box, it is skipped.

### WHAT THE USER SEES

![alt text](https://raw.githubusercontent.com/blomstertj/root/master/Cisco%20Prime%20Works/Bulk%20Add%20DNS%20Servers/Form%20View.PNG)

### FINAL CODE
```
#if ( $remove_dns_serv eq "true" )
		no ip name-server
	#end
ip name-server $dns_serv_1
#if ( $dns_serv_2 != "" )
		ip name-server $dns_serv_2
	#end
```
