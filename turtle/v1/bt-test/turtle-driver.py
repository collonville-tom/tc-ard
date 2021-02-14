#!flask/bin/python

import bluetooth

device_mac_addr = "00:1B:10:30:45:A3"
device_name = "ELET_SPP_3045A3"





def main():
    print("Laucch bluetooth app")
    # app.run(debug=True, port=5001, host='0.0.0.0')
    #devices = bluetooth.discover_devices(lookup_names=True, lookup_class=True)
    #scan(devices)
    print(bluetooth.lookup_name(device_mac_addr))
    sock = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
    sock.connect((device_mac_addr,3))
    sock.send('${"value": "thomas"}#')
    sock.close()


def scan(devices):
    print("Scanning for bluetooth devices:")
    number_of_devices = len(devices)
    print(number_of_devices, "devices found")
    for addr, name, device_class in devices:
        print("Device:")
        print("Device Name: %s" % (name))
        print("Device MAC Address: %s" % (addr))
        print("Device Class: %s" % (device_class))
        print("Services Found:")
        try:
            services = bluetooth.find_service(address=addr)
            if len(services) <= 0:
                print("zero services found on", addr)
            else:
                for serv in services:
                    print(serv['name'])
        except OSError:
            print("Oops!  That was no valid services.  Try again...")


if __name__ == '__main__':
    main()
