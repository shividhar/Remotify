if pgrep -x 'Spotify' &> /dev/null; then
  currentApp="Spotify"
elif pgrep -x 'iTunes'  &> /dev/null; then
  currentApp="iTunes"
fi

currentSong= #assumes theres no track change if same named song by different artisst is cycled
prevSong="14"

playerData="$(osascript -e 'tell application "'$currentApp'" to name of current track')"$"~"$"$(osascript -e 'tell application "'$currentApp'" to artist of current track')"
echo $playerData > /dev/cu.usbmodem0E2198D1

while true
do
  if pgrep -x 'Spotify' &> /dev/null; then
    currentApp="Spotify"
  elif pgrep -x 'iTunes'  &> /dev/null; then
    currentApp="iTunes"
  fi
  currentSong="$(osascript -e 'tell application "'$currentApp'" to name of current track')"
  if [ "$prevSong" != "$currentSong" ]
  then
    playerData="$(osascript -e 'tell application "'$currentApp'" to name of current track')"$"~"$"$(osascript -e 'tell application "'$currentApp'" to artist of current track')"
    echo $playerData > /dev/cu.usbmodem0E2198D1
    prevSong=$currentSong
  fi
done

#playerPos="$(osascript -e 'tell application "iTunes" to player position')"
#echo $playerPos > /dev/cu.usbmodem0E2198D1
