import socket
import pickle
from datetime import date
import os
#lsof -i :8080 util para limpar o "cache" da porta

class Pessoa:
    def __init__(self, nome="Unknown", nasc=1989):
        self.nome = nome
        self.nasc = nasc
        self.idade = None
        
def calcula_idade(nasc):
    return date.today().year-nasc
        
if __name__ == "__main__":
    os.system('lsof -i :8080')
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('localhost', 8080))
    server_socket.listen(1)
    
    conn, addr = server_socket.accept()
    while True:
        data = conn.recv(4096)
        pessoa = pickle.loads(data)
        pessoa.idade = calcula_idade(pessoa.nasc)
        print(pessoa.__dict__)
        conn.sendall(str(pessoa.idade).encode())
        
    conn.close()