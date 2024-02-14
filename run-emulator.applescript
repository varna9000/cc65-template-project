tell application "Virtual ]["
	activate
	close every machine saving no
	make new AppleIIPlus
	set theDisk to disk folder & "testproj.po"
	tell front machine
		set monochrome screen to true
		set speed to maximum
		insert theDisk into device "S6D1"
		type line "BRUN TESTPROJ"
	end tell
end tell