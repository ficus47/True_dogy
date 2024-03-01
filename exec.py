import psutil
import time as t
import os

def display_system_info():
    # Informations sur l'utilisation de la RAM
    ram = psutil.virtual_memory()
    print(f"Total RAM: {ram.total / (1024 ** 3):.2f} GB")
    print(f"RAM utilisée: {ram.used / (1024 ** 3):.2f} GB")
    print(f"RAM libre: {ram.available / (1024 ** 3):.2f} GB")
    print(f"Pourcentage d'utilisation de la RAM: {ram.percent}%\n")

    # Informations sur l'utilisation du CPU
    cpu = psutil.cpu_percent(interval=1, percpu=True)
    print("Utilisation du CPU par coeur:")
    for i, cpu_percent in enumerate(cpu):
        print(f"Core {i}: {cpu_percent}%")
    print(f"\nUtilisation totale du CPU: {sum(cpu) / psutil.cpu_count()}%")

while True:
    # Appel de la fonction pour afficher les informations
    display_system_info()
    t.sleep(3)
    os.system("clear")
