
{"sky_moon"
	{on spawn
		{add_view	"sky_moon_light"			"moonlight"			"moonlight"}
		{view start	"moonlight"}
		{view show	"moonlight"}
	}
}


{"sky_sun"
	{on spawn
		{ani_play "sun" 0.4}
		{add_view	"sky_sun_light"			"sun"			"sun_bone"}
		{view start	"sun"}
		{view show	"sun"}
	}
}


{"sky_clouds"
	{on spawn
		{call "sky_clouds"}
	}
	{on "sky_clouds"
		(define "sky_clouds" 
			{if rand %rand
				{spawn "thunder_rand"  "%spawn"}
				{if rand 0.2
					{spawn "thunder_sound"  "%spawn"} ;sound
				}

			}
		)
		("sky_clouds" rand(0.2)    spawn(haze00)   )
		("sky_clouds" rand(0.2)    spawn(haze01)   )
		("sky_clouds" rand(0.2)    spawn(haze02)   )
		("sky_clouds" rand(0.2)    spawn(haze03)   )
		("sky_clouds" rand(0.2)    spawn(haze04)   )
		("sky_clouds" rand(0.2)    spawn(haze05)   )
		("sky_clouds" rand(0.2)    spawn(haze06)   )
		("sky_clouds" rand(0.2)    spawn(haze07)   )
		("sky_clouds" rand(0.2)    spawn(haze08)   )
		("sky_clouds" rand(0.2)    spawn(haze09)   )
		("sky_clouds" rand(0.2)    spawn(haze10)   )
		("sky_clouds" rand(0.2)    spawn(haze11)   )
		("sky_clouds" rand(0.2)    spawn(haze12)   )
		("sky_clouds" rand(0.2)    spawn(haze13)   )
		("sky_clouds" rand(0.2)    spawn(haze14)   )
		{delay_effect 50 25 "sky_clouds"}
	
	}	
}
