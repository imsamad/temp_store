SSH 
 Network protocol provie seured tarnsport between two devices.
 Exchange pwd and data encrypted.
 It employs simple server/client relationship.
 Server - Remote device to connect
 Client - Device connecting to server.
 Both must have their respective SSH programs installed.
 Client - Will need to have the ssh command available
 Server - Need the running sshd deamon   

Authentication Mathod
    - Pwd-based 
        - server prompt client to enter pwd, which then be checked aginst
            the entries in /etc/passwd file.
    - Keys-based
        - Employs public and private keys and bypass pwd prompt altogether
        - Hit ssh-keygen , ~/.ssh/id_rsa, ~/.ssh/id_rsa.pub 
        - Copy id_rsa.pub to server ~/.ssh/authorized_keys file
    
    - Host - based 
        - Allow single user or group of users on the client to be authenticted on the server
        - On server, file is configured to allow some specific hosts to connect to server.

OpenSSH
    - Free and open-source implementation of SSH.
    Has 3 packages
        - OpenSSH - provides the ssh-keygen cmd
        - Openssh-client, scp etc
        - openssh-server - have running sshd deamon

ssh username@ip_adddress

ssh-keygen

ssh-copy-id username@ip_adddress


scp -R user1@ip1:path_to_file_1 user2@ip2:path_to_file_2
    -R if directory
