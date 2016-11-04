#!/bin/bash
# My first s`cript

input="$1"
echo $1
case "$1" in
play)
osascript -e 'tell application "iTunes" to play';;

pause)
osascript -e 'tell application "iTunes" to pause';;

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

repeatOff)
osascript -e 'tell application "iTunes" to set repeat enabled to off';;

mute)
osascript -e 'tell application "iTunes" to set sound volume to 0';;
esac
