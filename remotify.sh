##### Initialization ######
trap 'kill $(jobs -p)' EXIT
sh playerData.sh &

if pgrep -x 'Spotify' &> /dev/null; then
  currentApp="Spotify"
elif pgrep -x 'iTunes'  &> /dev/null; then
  currentApp="iTunes"
fi
###########################

function readIn
{
  read -e STR < /dev/cu.usbmodem0E2198D1;
}

while true
do
  readIn 2> /dev/null
  # add while loop with nothing curretn app condition
  if pgrep -x 'Spotify'  &> /dev/null; then
    currentApp="Spotify"
  elif pgrep -x 'iTunes'  &> /dev/null; then
    currentApp="iTunes"
  fi

  case "${STR:0:1}" in
    a) #playpause toggle
    osascript -e 'tell application "'$currentApp'" to playpause';;

    b) #next track
    osascript -e 'tell application "'$currentApp'" to play next track';;

    c) #previous track
    osascript -e 'tell application "'$currentApp'" to play previous track';;

    d) #turn repeat on
    if [ "$currentApp" = "Spotify" ]
    then
      osascript -e 'tell application "Spotify" to set repeating to true'
    elif [ "$currentApp" = "iTunes" ]
    then
      osascript -e 'tell application "iTunes" to set song repeat to all'
    fi;;

    e) #turn repeat off
    if [ "$currentApp" = "Spotify" ]
    then
      osascript -e 'tell application "Spotify" to set repeating to false'
    elif [ "$currentApp" = "iTunes" ]
    then
      osascript -e 'tell application "iTunes" to set song repeat to off'
    fi;;

    f) #mute
    osascript -e 'set volume output muted true';;

    g) #unmute
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
done
