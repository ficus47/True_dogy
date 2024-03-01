import psutil
import time as t
import os
import matplotlib.pyplot as plt

def display_system_info(a, b, c):
    # Informations sur l'utilisation de la RAM
    ram = psutil.virtual_memory()
    print(f"Total RAM: {ram.total / (1024 ** 3):.2f} GB")
    print(f"RAM utilisée: {ram.used / (1024 ** 3):.2f} GB")
    print(f"RAM libre: {ram.available / (1024 ** 3):.2f} GB")
    print(f"Pourcentage d'utilisation de la RAM: {ram.percent}%\n")
    b.append(ram.percent)
    a.append(ram.used / (1024 ** 3))

    # Informations sur l'utilisation du CPU
    cpu = psutil.cpu_percent(interval=1, percpu=True)
    print("Utilisation du CPU par coeur:")
    for i, cpu_percent in enumerate(cpu):
        print(f"Core {i}: {cpu_percent}%")
    print(f"\nUtilisation totale du CPU: {sum(cpu) / psutil.cpu_count()}%")
    c.append(sum(cpu) / psutil.cpu_count())
    return a, b, c

a, b, c = [], [], []

while True:
    # Appel de la fonction pour afficher les informations
    a, b, c = display_system_info(a, b, c)

    t.sleep(3)
    os.system("clear")

    plt.figure(figsize=(12, 8))
    plt.plot(a, label="RAM utilisée", color="red")
    plt.plot(b, label="RAM utilisée pourcentage", color="blue")
    plt.plot(c, label="pourcentage de CPU utilisée", color="green")

    plt.legend()
    plt.savefig("image.png")