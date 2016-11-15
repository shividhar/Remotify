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
currentSong=
prevSong="14"
while true  
        do
        	readIn 2> /dev/null

        	if pgrep -x 'Spotify' &> /dev/null; then
                currentApp="Spotify"
            elif pgrep -x 'iTunes'  &> /dev/null; then
                currentApp="iTunes"
            fi

            currentSong="$(osascript -e 'tell application "'$currentApp'" to name of current track')"

            case "${STR:0:1}" in
#           playpause toggle
                0)
                    osascript -e 'tell application "'$currentApp'" to playpause';;

#           next track
                1)
                    osascript -e 'tell application "'$currentApp'" to play next track'
                    playerData="$(osascript -e 'tell application "'$currentApp'" to name of current track')"$"~"$"$(osascript -e 'tell application "'$currentApp'" to artist of current track')"
                    echo $playerData > /dev/cu.usbmodem0E2198D1;;

#           previous track
                2)
                    osascript -e 'tell application "'$currentApp'" to play previous track';;

#           turn repeat on
                3)
                    if [ "$currentApp" = "Spotify" ]
                    then
                        osascript -e 'tell application "Spotify" to set repeating to true'
                    elif [ "$currentApp" = "iTunes" ]
                    then
                        osascript -e 'tell application "iTunes" to set song repeat to all'
                    fi;;

#           turn repeat off
                4)
                    if [ "$currentApp" = "Spotify" ]
                    then
                        osascript -e 'tell application "Spotify" to set repeating to false'
                    elif [ "$currentApp" = "iTunes" ]
                    then
                        osascript -e 'tell application "iTunes" to set song repeat to off'
                    fi;;

#           mute
                5)
                    osascript -e 'set volume output muted true';;
#           unmute
                6)
                    osascript -e 'set volume output muted false';;
#                7)
#					echo "hit"
#					playerState="$(osascript -e 'tell application "Spotify" to player state')"
#					echo $playerState > /dev/cu.usbmodem0E2198D1;;
                v)
                    vol=${STR:1:1}${STR:2:1}
                    osascript -e 'tell application "'$currentApp'" to set sound volume to '$vol''

#               shuffle)
#                    shuffleState="$(osascript -e 'tell application "'$currentApp'" to shuffle enabled')"
#                    if [ $shuffleState = "true" ]
#                    then
#                        osascript -e 'tell application "'$currentApp'" to set shuffle enabled to false'
#                    else
#                        osascript -e 'tell application "'$currentApp'" to set shuffle enabled to true'
#                    fi
#                    ;;
            esac

            if [ "$prevSong" != "$currentSong" ]
            then
                playerData="$(osascript -e 'tell application "'$currentApp'" to name of current track')"$"~"$"$(osascript -e 'tell application "'$currentApp'" to artist of current track')"
                echo $playerData > /dev/cu.usbmodem0E2198D1
                prevSong=$currentSong
            fi
            # playerData="$(osascript -e 'tell application "'$currentApp'" to name of current track')"$"~"$"$(osascript -e 'tell application "'$currentApp'" to artist of current track')"
            # echo $playerData > /dev/cu.usbmodem0E2198D1
            # sleep 1
done
#
    #		playerPos="$(osascript -e 'tell application "iTunes" to player position')"
	#        echo $playerPos > /dev/cu.usbmodem0E2198D1
			# playerPos="$(osascript -e 'tell application "iTunes" to player position')"
	  #       echo $playerPos > /dev/cu.usbmodem0E2198D1

