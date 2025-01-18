	{on "unlink_weapon"
		{tags remove "m37_link"}
		{if effector "stuff weapon"		
			{with_effector
				{call "unlink"}
				;{set "link_weapon" 0}
				{tags remove "link_weapon"}
			}
		}
		{tags remove "link_weapon"}
		(define "link_weapon"
			{if effector %0
				{call "unlink"}
				{tags remove "link_weapon"}
				{tags remove %0}
				{start_sound "executions/%1/"}
			}
		)		
		("link_weapon" args "pistol"	 		pistol)
		("link_weapon" args "smg"	 			smg)
		("link_weapon" args "mgun"	 			big)
		("link_weapon" args "rifle"	 			rifle)
		("link_weapon" args "sniper"	 		sniper)
		("link_weapon" args "rocketlauncher"	rpg)
		("link_weapon" args "knife"	 			knife)
		("link_weapon" args "grenade"	 		grenade)
	}
