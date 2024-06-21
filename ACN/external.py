ip = input('Enter the IP address:')


def check_ip(ip):
    # ip = ip.split('.')
    if len(ip) !=4:
        return False

    for i in ip:
        if not i.isdigit():
            return False
        i = int(i)
        if i<0 or i>255:
            return False
    return True
    

def check_class(ip):
    ip = ip.split('.')
    if(check_ip(ip)):
        print('IP is valid')
        ip = list(map(int, ip))
        if ip[0] >= 0 and ip[0]<= 127:
            print('Class A')
        elif (ip[0] >= 128 and ip[0]<= 191):
            print('Class B')
        elif (ip[0] >= 192 and ip[0]<= 223):
            print('Class C')
        elif (ip[0] >= 224 and ip[0]<= 239):
            print('Class D')
        elif (ip[0] >= 240 and ip[0]<= 255):
            print('Class E')
    else:
        print('Invalid IP')

# check_class(ip)

def custom_mask(ip):
    ip,ip_subnet = ip.split('/')
    ip_subnet = int(ip_subnet)
    if(ip_subnet<=32):
        res = 32-ip_subnet
        if(ip_subnet>=24):
            print(f'subnet mask is 255.255.255.{256-2**res}')
        elif(ip_subnet>=16):
            print(f'subnet mask is 255.255.{256-2**(res-8)}.0')
        elif(ip_subnet>=8):
            print(f'subnet mask is 255.{256-2**(res-16)}.0.0')
        else:
            print(f'subnet mask is {256-2**(res-24)}.0.0.0')
    else:
        print('Invalid subnet mask')

# custom_mask(ip); 

choice = int(input('Enter 1 to check class and 2 to check subnet: '))

if(choice == 1):
    check_class(ip)
elif(choice == 2):
    custom_mask(ip)
else:
    print('Invalid choice')

