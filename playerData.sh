##### Initialization ######
currentApp=
if pgrep -x 'Spotify' &> /dev/null; then
  currentApp="Spotify"
elif pgrep -x 'iTunes'  &> /dev/null; then
  currentApp="iTunes"
fi

previousSong=
if [ ${currentApp}  ]
  then
  playerData="$(osascript -e 'tell application "'$currentApp'" to name of current track')"$" ~"$"$(osascript -e 'tell application "'$currentApp'" to artist of current track')"
  echo $playerData > /dev/cu.usbmodem0E2198D1
fi
########################################

while true
do
  if pgrep -x 'Spotify' &> /dev/null; then
    currentApp="Spotify"
  elif pgrep -x 'iTunes'  &> /dev/null; then
    currentApp="iTunes"
  fi
  if [ ${currentApp} ]
    then
    currentSong="$(osascript -e 'tell application "'$currentApp'" to name of current track')"$" ~"$"$(osascript -e 'tell application "'$currentApp'" to artist of current track')"
    if [ "$previousSong" != "$currentSong" ]
    then
      playerData="$(osascript -e 'tell application "'$currentApp'" to name of current track')"$" ~"$"$(osascript -e 'tell application "'$currentApp'" to artist of current track')"
      echo $playerData > /dev/cu.usbmodem0E2198D1
      previousSong=$currentSong
    fi
  fi
done

#playerPos="$(osascript -e 'tell application "iTunes" to player position')"
#echo $playerPos > /dev/cu.usbmodem0E2198D1
