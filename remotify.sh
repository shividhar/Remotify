#!/bin/bash
while true  
        do
         read -e STR < /dev/cu.usbmodem0E2198D1
         case "$STR" in
		 	playpause)
		 		osascript -e 'tell application "iTunes" to playpause';;
			 
		 	next)
		 		osascript -e 'tell application "iTunes" to play next track';;
			 
		 	previous)
		 		osascript -e 'tell application "iTunes" to play previous track';;
			 
		 	shuffle)
		 		shuffleState="$(osascript -e 'tell application "iTunes" to shuffle enabled')"
		 		if [ $shuffleState = "true" ]
		 		then
		 		    osascript -e 'tell application "iTunes" to set shuffle enabled to false'
		 		else
		 		    osascript -e 'tell application "iTunes" to set shuffle enabled to true'
		 		fi
		 		;;
		 
		 	repeatOn)
                osascript -e 'tell application "iTunes" to set song repeat to all';;

            repeatOff)
                osascript -e 'tell application "iTunes" to set song repeat to off';;

            muteOn)
                osascript -e 'set volume output muted true';;

            muteOff)
		 		osascript -e 'set volume output muted false';;

		 esac
#       currentSong="$(osascript -e 'tell application "iTunes" to name of current track')"
#       currentArtist="$(osascript -e 'tell application "iTunes" to album of current track')"
#       currentAlbum="$(osascript -e 'tell application "iTunes" to artist of current track')"
#		playerPos="$(osascript -e 'tell application "iTunes" to player position')"
#        echo $currentSong > /dev/cu.usbmodem0E2198D1
#        echo $currentArtist > /dev/cu.usbmodem0E2198D1
#        echo $currentAlbum > /dev/cu.usbmodem0E2198D1
#        echo $playerPos > /dev/cu.usbmodem0E2198D1
#        sleep 1
done
