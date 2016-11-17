##### Initialization ######
if pgrep -x 'Spotify' &> /dev/null; then
  currentApp="Spotify"
elif pgrep -x 'iTunes'  &> /dev/null; then
  currentApp="iTunes"
fi
playerData="$(osascript -e 'tell application "'$currentApp'" to name of current track')"$"~"$"$(osascript -e 'tell application "'$currentApp'" to artist of current track')"
echo $playerData > /dev/cu.usbmodem0E2198D1
###########################

function readIn
{
  read -e STR < /dev/cu.usbmodem0E2198D1;
}

currentSong= #assumes theres no track change if same named song by different artisst is cycled
prevSong="14"

while true
do
  readIn 2> /dev/null
  # add while loop with nothing curretn app condition
  if pgrep -x 'Spotify'  &> /dev/null; then
    currentSong="$(osascript -e 'tell application "'$currentApp'" to name of current track')"
    currentApp="Spotify"
  elif pgrep -x 'iTunes'  &> /dev/null; then
    currentSong="$(osascript -e 'tell application "'$currentApp'" to name of current track')"
    currentApp="iTunes"
  fi

  case "${STR:0:1}" in
    0) #playpause toggle
    osascript -e 'tell application "'$currentApp'" to playpause';;

    1) #next track
    osascript -e 'tell application "'$currentApp'" to play next track'
    playerData="$(osascript -e 'tell application "'$currentApp'" to name of current track')"$"~"$"$(osascript -e 'tell application "'$currentApp'" to artist of current track')"
    echo $playerData > /dev/cu.usbmodem0E2198D1;;

    2) #previous track
    osascript -e 'tell application "'$currentApp'" to play previous track';;

    3) #turn repeat on
    if [ "$currentApp" = "Spotify" ]
    then
      osascript -e 'tell application "Spotify" to set repeating to true'
    elif [ "$currentApp" = "iTunes" ]
    then
      osascript -e 'tell application "iTunes" to set song repeat to all'
    fi;;

    4) #turn repeat off
    if [ "$currentApp" = "Spotify" ]
    then
      osascript -e 'tell application "Spotify" to set repeating to false'
    elif [ "$currentApp" = "iTunes" ]
    then
      osascript -e 'tell application "iTunes" to set song repeat to off'
    fi;;

    5) #mute
    osascript -e 'set volume output muted true';;

    6) #unmute
    osascript -e 'set volume output muted false';;

    v) #volume
    vol=${STR:1:1}${STR:2:1}
    osascript -e 'tell application "'$currentApp'" to set sound volume to '$vol''

    #shuffle)
    #shuffleState="$(osascript -e 'tell application "'$currentApp'" to shuffle enabled')"
    #if [ $shuffleState = "true" ]
    #then
    # osascript -e 'tell application "'$currentApp'" to set shuffle enabled to false'
    #else
    # osascript -e 'tell application "'$currentApp'" to set shuffle enabled to true'
    #fi
    #;;
  esac

  if [ "$prevSong" != "$currentSong" ]
  then
    playerData="$(osascript -e 'tell application "'$currentApp'" to name of current track')"$"~"$"$(osascript -e 'tell application "'$currentApp'" to artist of current track')"
    echo $playerData > /dev/cu.usbmodem0E2198D1
    prevSong=$currentSong
  fi
done
#playerPos="$(osascript -e 'tell application "iTunes" to player position')"
#echo $playerPos > /dev/cu.usbmodem0E2198D1
