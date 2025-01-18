game_entity
	{props "construction" }
	{collider "construction"}
	{obstacleID "construction"}
	{mass 300}
;	(include "/properties/shadow/construction.inc" sx(1) sy(0.18))
	(include "construction_generic.inc")
	{lodclass "decor_big"}
	(define "add_climb_bones"
		{bone "%0"
			{bone "left_%0"
				{Matrix34
					{pos 8 8 0}
					{xform 0 -0.79 0}
				}
			}
			{bone "right_%0"
				{Matrix34
					{pos 8 -8 0}
					{xform 0 0.79 0}
				}
			}
		}
	)	
