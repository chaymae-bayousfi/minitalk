# 🗨️ minitalk

Bienvenue dans **minitalk** !  
Un projet de communication interprocessus simple utilisant les signaux Unix pour échanger des messages entre un client et un serveur.  
Ce projet a été réalisé dans le cadre de la formation 42.

---

## 🚀 Présentation

**minitalk** permet d'envoyer des messages en texte clair d'un client vers un serveur grâce à la transmission de signaux (`SIGUSR1` et `SIGUSR2`).  
Chaque caractère du message est transmis bit à bit, rendant ce projet idéal pour s’initier à la manipulation bas niveau des signaux et à la communication entre processus sous UNIX/Linux.

---

## 🗂️ Structure du projet

```
minitalk/
│
├── client.c           # Programme client
├── server.c           # Programme serveur
├── minitalk.h         # Header commun
│
├── printf/            # Mini-libftprintf pour affichage formaté
│   ├── ft_printf.c
│   └── ... (autres fichiers de la mini-lib)
│
├── Makefile           # Compilation générale
└── README.md          # Ce fichier !
```

---

## ⚙️ Compilation

Compilez le projet facilement avec :

```sh
make
```

Cela générera deux exécutables :

- `server`
- `client`

---

## 🖥️ Utilisation

### 1️⃣ Lancer le serveur

Dans un premier terminal :

```sh
./server
```

Vous verrez afficher le PID du serveur (par exemple : `Server PID: 12345`).

---

### 2️⃣ Envoyer un message depuis le client

Dans un second terminal :

```sh
./client <PID_du_serveur> "Votre message ici"
```

**Exemple :**
```sh
./client 12345 "Bonjour, minitalk 🚀"
```

Le serveur affichera alors le message reçu dans son terminal.

---

## 🔄 Exemple d'interaction

```shell
# Terminal 1 : Lancement du serveur
$ ./server
Server PID: 45678
En attente de message...

# Terminal 2 : Envoi du message
$ ./client 45678 "Hello 42!"
```

**Résultat dans le serveur :**
```
Message reçu : Hello 42!
```

---

## 🛠️ Fonctions principales

- **Transmission bit à bit** via signaux `SIGUSR1` et `SIGUSR2`
- **Gestion d’erreurs** (arguments invalides, PID incorrect, message vide, etc.)
- **Librairie printf minimale** fournie (pas de dépendance externe)

---

## ⚠️ Contraintes

- Aucun usage de threads
- Uniquement les signaux pour la communication
- Code conforme aux standards 42

---

## 📄 Aide & contact

Pour toute question ou suggestion, n’hésitez pas à ouvrir une **issue** ou à me contacter sur [42 intra](mailto:cbayousf@student.42.fr).

---

## 💡 Astuces

- N'oubliez pas de bien vérifier le PID du serveur avant d'envoyer un message.
- Vous pouvez envoyer n'importe quel texte (y compris des emoji ! 😄).
- Le projet est un excellent point de départ pour comprendre les IPC (Inter Process Communication) sous Linux.

---

## 📝 License

Projet réalisé dans le cadre de l'école 42, usage académique.

---

**Happy Coding!** 🚦👨‍💻👩‍💻
