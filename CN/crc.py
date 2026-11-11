
def crc(data, key):
    data = list(data + '0' * (len(key) - 1))

    for i in range(len(data) - len(key) + 1):
        if data[i] == '1':
            for j in range(len(key)):
                data[i + j] = str(int(data[i + j]) ^ int(key[j]))

    return ''.join(data[-(len(key) - 1):])


data = input("Enter data: ")
key = input("Enter generator: ")

remainder = crc(data, key)
codeword = data + remainder

print("CRC:", remainder)
print("Codeword:", codeword)
