#!/bin/bash
while true  
        do
        	read -e STR < /dev/cu.usbmodem0E2198D1
        	if pgrep -x 'Spotify' &> /dev/null; then
	         	case "${STR:0:1}" in
#           playpause toggle
				 	0)
				 		osascript -e 'tell application "Spotify" to playpause';;

#           next track
				 	1)
				 		osascript -e 'tell application "Spotify" to play next track';;

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

				esac
	        elif pgrep -x 'iTunes'  &> /dev/null; then
	         	case "${STR:0:1}" in
#           playpause toggle
                    0)
                        osascript -e 'tell application "iTunes" to playpause';;

#           next track
                    1)
                        osascript -e 'tell application "iTunes" to play next track';;

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
#       currentSong="$(osascript -e 'tell application "iTunes" to name of current track')"
#       currentArtist="$(osascript -e 'tell application "iTunes" to album of current track')"
#       currentAlbum="$(osascript -e 'tell application "iTunes" to artist of current track')"
#		playerPos="$(osascript -e 'tell application "iTunes" to player position')"
#       echo $currentSong > /dev/cu.usbmodem0E2198D1
#       echo $currentArtist > /dev/cu.usbmodem0E2198D1
#       echo $currentAlbum > /dev/cu.usbmodem0E2198D1
#       echo $playerPos > /dev/cu.usbmodem0E2198D1
#       sleep 1
done
