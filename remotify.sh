#!/bin/bash

##### Initialization #####
currentSong="$(osascript -e 'tell application "Spotify" to name of current track')"$"~"$"$(osascript -e 'tell application "Spotify" to artist of current track')"
# currentSong="$(osascript -e 'tell application "iTunes" to name of current track')"$"~"$"$(osascript -e 'tell application "iTunes" to artist of current track')"
echo $currentSong > /dev/cu.usbmodem0E2198D1
##########################

function readIn
{
	read -e STR < /dev/cu.usbmodem0E2198D1;
}

while true  
        do
        	readIn 2> /dev/null
        	if pgrep -x 'Spotify' &> /dev/null; then
	         	case "${STR:0:1}" in
#           playpause toggle
				 	0)
				 		osascript -e 'tell application "Spotify" to playpause';;

#           next track
				 	1)
				 		osascript -e 'tell application "Spotify" to play next track'
				 		currentSong="$(osascript -e 'tell application "Spotify" to name of current track')"$"~"$"$(osascript -e 'tell application "Spotify" to artist of current track')"
						echo $currentSong > /dev/cu.usbmodem0E2198D1;;

#           previous track
				 	2)
				 		osascript -e 'tell application "Spotify" to play previous track';;

#           turn repeat on
				 	3)
		                osascript -e 'tell application "Spotify" to set repeating to true';;

#           turn repeat off
		            4)
		                osascript -e 'tell application "Spotify" to set repeating to false';;
#           mute
		            5)
		                osascript -e 'set volume output muted true';;
#           unmute
		            6)
				 		osascript -e 'set volume output muted false';;
				 	7)
						echo "hit"
						playerState="$(osascript -e 'tell application "Spotify" to player state')"
						echo $playerState > /dev/cu.usbmodem0E2198D1;;
                    v)
                        vol=${STR:1:1}${STR:2:1}${STR:3:1}
                        osascript -e 'tell application "Spotify" to set sound volume to '$vol''

#                    shuffle)
#                    shuffleState="$(osascript -e 'tell application "Spotify" to shuffle enabled')"
#                    if [ $shuffleState = "true" ]
#                    then
#                        osascript -e 'tell application "Spotify" to set shuffle enabled to false'
#                    else
#                        osascript -e 'tell application "Spotify" to set shuffle enabled to true'
#                    fi
#                    ;;
					# currentSong="$(osascript -e 'tell application "Spotify" to name of current track')"
					# echo $currentSong > /dev/cu.usbmodem0E2198D1
					# sleep 2
				esac
	        elif pgrep -x 'iTunes'  &> /dev/null; then
	         	case "${STR:0:1}" in
#           playpause toggle
                    0)
                        osascript -e 'tell application "iTunes" to playpause';;

#           next track
                    1)
                        osascript -e 'tell application "iTunes" to play next track'
                        currentSong="$(osascript -e 'tell application "iTunes" to name of current track')"$"~"$"$(osascript -e 'tell application "iTunes" to artist of current track')"
                        echo $currentSong > /dev/cu.usbmodem0E2198D1;;

#           previous track
                    2)
                        osascript -e 'tell application "iTunes" to play previous track';;

#           turn repeat on
                    3)
                        osascript -e 'tell application "iTunes" to set song repeat to all';;

#           turn repeat off
                    4)
                        osascript -e 'tell application "iTunes" to set song repeat to off';;

#           mute
                    5)
                        osascript -e 'set volume output muted true';;

#           unmute
                    6)
                        osascript -e 'set volume output muted false';;

                    v)
                        vol=${STR:1:1}${STR:2:1}${STR:3:1}
                        osascript -e 'tell application "iTunes" to set sound volume to '$vol''

#           shuffle
#                    shuffle)
#                        shuffleState="$(osascript -e 'tell application "iTunes" to shuffle enabled')"
#                        if [ $shuffleState = "true" ]
#                        then
#                            osascript -e 'tell application "iTunes" to set shuffle enabled to false'
#                        else
#                            osascript -e 'tell application "iTunes" to set shuffle enabled to true'
#                        fi
#                        ;;
				esac
	        fi
    #		playerPos="$(osascript -e 'tell application "iTunes" to player position')"
	#        echo $playerPos > /dev/cu.usbmodem0E2198D1
			# playerPos="$(osascript -e 'tell application "iTunes" to player position')"
	  #       echo $playerPos > /dev/cu.usbmodem0E2198D1
done
