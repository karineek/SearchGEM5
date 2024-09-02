sudo apt update
sudo apt install apt-transport-https curl gnupg-agent ca-certificates software-properties-common -y
sudo apt install docker.io
sudo usermod -aG docker $USER
