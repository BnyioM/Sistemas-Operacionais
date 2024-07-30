import socket
import pickle
import random
from datetime import datetime, timedelta

class Pessoa:
    def __init__(self, nome="Unknown", nasc=1989):
        self.nome = nome
        self.nasc = nasc
        self.idade = None

def random_nasc(start_year=1900):
    end_year = datetime.now().year
    
    return random.randint(start_year, end_year-1)

if __name__ == "__main__":
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect(('localhost', 8080))
    
    ####Não Altere essa parte de geracao dos objetos
    objects = []
    for i in range(0, 50):
        obj = Pessoa('Pessoa'+str(i), random_nasc())
        print(obj.__dict__)
        objects.append(obj)
    
    while True:
        message = input("Press Button")#Não altere essa linha
        p = random.randint(0, len(objects) - 1)#Seleciona um objeto qualquer da Lista
        
        print(objects[p].__dict__) #Não altere essa linha
        
    client_socket.close()