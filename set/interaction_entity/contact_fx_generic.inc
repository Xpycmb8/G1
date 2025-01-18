(define "contact_fx_generic"
	{"%prop"
		{on contact
			{if not effector "obstacle"
				{if not effector "human"
					{if prop "%prop"	
						{if contact_velocity %speed_max ;2
							{with_effector
								{if min_mass %mass_max ;5
									{spawn "spheredust_small_short"}
									{call "generic_15"}
								else min_mass %mass_min ;4
									;{tags add "%mass_min"}
									{spawn "spheredust_small_short2"}
									{call "generic_5"}
								else min_mass 0.3
								}
							}
						else contact_velocity %speed_min ;3
							{with_effector
								{if min_mass %mass_max ;5
									{spawn "spheredust_small_short"}
									{call "generic_15"}
								else min_mass %mass_min ;4
									{spawn "spheredust_small_short2"}
									{call "generic_5"}
								else min_mass 0.3
								}
							}
						}
					}
				}
			}
		}
		{on "generic_15"	
			{start_sound "hit/generic/%sound/15"}
		}
		{on "generic_5"	
			{start_sound "hit/generic/%sound/5"}
		}
	}
)
;                       ;props%0       			;sound%1	      	 	;speed%2-3  	           mass_min%4  	mass_max%5 		wound(6)
("contact_fx_generic" 	prop(small_tire) 		sound(rubber_tire)    	speed_max(15) speed_min(2) mass_min(10) mass_max(100) )
("contact_fx_generic" 	prop(metal_auto) 		sound(hit_small)     	speed_max(15) speed_min(2) mass_min(10) mass_max(100) )
("contact_fx_generic" 	prop(rubberball) 		sound(rubberball)     	speed_max(15) speed_min(2) mass_min(10) mass_max(100) )
("contact_fx_generic" 	prop(barrel_small) 		sound(barrel)    		speed_max(15) speed_min(2) mass_min(10) mass_max(100) )
("contact_fx_generic" 	prop(body) 				sound(body)     		speed_max(15) speed_min(2) mass_min(10) mass_max(100) )
("contact_fx_generic" 	prop(box_cardboard) 	sound(box)     			speed_max(15) speed_min(2) mass_min(10) mass_max(100) )
("contact_fx_generic" 	prop(ceramic) 			sound(ceramic)     		speed_max(15) speed_min(2) mass_min(10) mass_max(100) )
("contact_fx_generic" 	prop(bottle) 			sound(glass_bottle)     speed_max(15) speed_min(2) mass_min(10) mass_max(100) )
("contact_fx_generic" 	prop(bucket) 			sound(metal_bucket)     speed_max(15) speed_min(2) mass_min(10) mass_max(100) )
("contact_fx_generic" 	prop(metal_weight) 		sound(metal_weight)     speed_max(15) speed_min(2) mass_min(10) mass_max(100) )
("contact_fx_generic" 	prop(metal_small) 		sound(metal_small)     	speed_max(15) speed_min(2) mass_min(10) mass_max(100) )
("contact_fx_generic" 	prop(plastic) 			sound(plastic)     		speed_max(15) speed_min(2) mass_min(10) mass_max(100) )
("contact_fx_generic" 	prop(tire) 				sound(rubber_tire)     	speed_max(15) speed_min(2) mass_min(10) mass_max(100) )
("contact_fx_generic" 	prop(steel_props) 		sound(steel)     		speed_max(15) speed_min(2) mass_min(10) mass_max(100) )
("contact_fx_generic" 	prop(wood_props) 		sound(wood)     		speed_max(15) speed_min(2) mass_min(10) mass_max(100) )
("contact_fx_generic" 	prop(armor) 			sound(armor)     		speed_max(15) speed_min(2) mass_min(10) mass_max(100) )
("contact_fx_generic" 	prop(hit_medium) 		sound(hit_medium)     	speed_max(15) speed_min(2) mass_min(10) mass_max(100) )
("contact_fx_generic" 	prop(hit_small) 		sound(hit_small)		speed_max(15) speed_min(2) mass_min(10) mass_max(100) )
("contact_fx_generic" 	prop(hit_small_wood) 	sound(wood)				speed_max(15) speed_min(2) mass_min(10) mass_max(100) )
