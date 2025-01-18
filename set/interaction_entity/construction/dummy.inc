
{"lamp_spot_yellow_small"
	{on spawn
		{add_view 	"headlight_2500k_small"				"lamp_light"				"light_fx"}
		{add_view 	"headlight_2500k_small_stop"		"lamp_light_stop"			"light_fx"}
		{view hide "lamp_light"}
		{view hide "lamp_light_stop"}
		{call "update_lights"}
	}
	{on "break" overload
		{spawn "lamp_hit" "light_fx"}
		{bone cut "light"}
		{view stop "lamp_light"}
		{view hide "lamp_light"}
		{view start	"lamp_light_stop"}
		{view show	"lamp_light_stop"}
		{delay 1
			{view stop	"lamp_light_stop"}
			{view hide	"lamp_light_stop"}
		}			
	}
	{on "update_lights"
		{if not sunlight
			{call "lights_on"}
		else
			{call "lights_off"}
		}
	}
	{on "environment_changed"
		{call "update_lights"}
	}
	{on "lights_on" overload
		{view start "lamp_light"}
		{view show "lamp_light"}
		{bone show "light_ems"}
	}
	{on "lights_off" overload
		{view stop "lamp_light"}
		{view hide "lamp_light"}
		{bone hide "light_ems"}
	}
	{on break_armor overload
		{if volume "light"
			{spawn "lamp_hit" "light_fx"}
			{call "lights_off"}
			{bone cut "light"}
		}
	}
}

{"lamp_spot_yellow_long"
	{on spawn
		{add_view 	"light_lighthouse_spot_small"				"lamp_light"				"light_fx"}
		{view hide "lamp_light"}
		{call "update_lights"}
	}
	{on "break" overload
		{spawn "lamp_hit" "light_fx"}
		{bone cut "light"}
		{view stop "lamp_light"}
		{view hide "lamp_light"}
	}
	{on "update_lights"
		{if not sunlight
			{call "lights_on"}
		else
			{call "lights_off"}
		}
	}
	{on "environment_changed"
		{call "update_lights"}
	}
	{on "lights_on" overload
		{view start "lamp_light"}
		{view show "lamp_light"}
		{bone show "light_ems"}
	}
	{on "lights_off" overload
		{view stop "lamp_light"}
		{view hide "lamp_light"}
		{bone hide "light_ems"}
	}
	{on break_armor overload
		{if volume "light"
			{spawn "lamp_hit" "light_fx"}
			{call "lights_off"}
			{bone cut "light"}
		}
	}
}


{"lamp_spot_yellow"
	{on spawn
		{add_view 	"light_post_dir_yellow_add"		"lamp_light_spot1"			"lamp_light_spot1"}
		{add_view 	"light_post_dir_yellow_add"		"lamp_light_spot2"			"lamp_light_spot2"}
		{add_view 	"light_post_dir_yellow_add"		"lamp_light_spot3"			"lamp_light_spot3"}
		{add_view 	"light_post_dir_yellow_add"		"lamp_light_spot4"			"lamp_light_spot4"}
		{add_view 	"light_post_dir_yellow_add"		"lamp_light_spot5"			"lamp_light_spot5"}
		{add_view 	"light_post_dir_yellow_add"		"lamp_light_spot6"			"lamp_light_spot6"}
		{add_view 	"light_post_dir_yellow_add"		"lamp_light_spot7"			"lamp_light_spot7"}
		{add_view 	"light_post_dir_yellow_add"		"lamp_light_spot8"			"lamp_light_spot8"}
		{add_view 	"light_post_dir_yellow_add"		"lamp_light_spot9"			"lamp_light_spot9"}
		{add_view 	"light_post_dir_yellow_add"		"lamp_light_spot10"			"lamp_light_spot10"}
		{add_view 	"light_post_dir_yellow_add"		"lamp_light_spot11"			"lamp_light_spot11"}
		{add_view 	"light_post_dir_yellow_add"		"lamp_light_spot12"			"lamp_light_spot12"}
		{view hide "lamp_light_spot1"}
		{view hide "lamp_light_spot2"}
		{view hide "lamp_light_spot3"}
		{view hide "lamp_light_spot4"}
		{view hide "lamp_light_spot5"}
		{view hide "lamp_light_spot6"}
		{view hide "lamp_light_spot7"}
		{view hide "lamp_light_spot8"}
		{view hide "lamp_light_spot9"}
		{view hide "lamp_light_spot10"}
		{view hide "lamp_light_spot11"}
		{view hide "lamp_light_spot12"}
		{view hide "lamp_light_spot13"}
		{call "update_lights"}
	}
	{on "broken_power"
		{start_sound "hit/generic/metal_small/15/"}	
		{call "lights_off"}
		{delay 0.2
			{start_sound "hit/generic/metal_small/15/"}	
			{call "lights_on"}
			{delay 0.4
				{start_sound "hit/generic/metal_small/15/"}	
				{call "lights_off"}
			}
		}
	}
	{on "break"
		{view stop "lamp_light_spot1"}
		{view hide "lamp_light_spot1"}
		{view stop "lamp_light_spot2"}
		{view hide "lamp_light_spot2"}
		{view stop "lamp_light_spot3"}
		{view hide "lamp_light_spot3"}
		{view stop "lamp_light_spot4"}
		{view hide "lamp_light_spot4"}
		{view stop "lamp_light_spot5"}
		{view hide "lamp_light_spot5"}
		{view stop "lamp_light_spot6"}
		{view hide "lamp_light_spot6"}
		{view stop "lamp_light_spot7"}
		{view hide "lamp_light_spot7"}
	}
	{on "update_lights"
		{if not sunlight
			{call "lights_on"}
		else
			{call "lights_off"}
		}
	}
	{on "environment_changed"
		{call "update_lights"}
	}
	{on "lights_on"
		{view start "lamp_light_spot1"}
		{view show "lamp_light_spot1"}
		{view start "lamp_light_spot2"}
		{view show "lamp_light_spot2"}
		{view start "lamp_light_spot3"}
		{view show "lamp_light_spot3"}
		{view start "lamp_light_spot4"}
		{view show "lamp_light_spot4"}
		{view start "lamp_light_spot5"}
		{view show "lamp_light_spot5"}
		{view start "lamp_light_spot6"}
		{view show "lamp_light_spot6"}
		{view start "lamp_light_spot7"}
		{view show "lamp_light_spot7"}
		{view start "lamp_light_spot8"}
		{view show "lamp_light_spot8"}
		{view start "lamp_light_spot9"}
		{view show "lamp_light_spot9"}
		{view start "lamp_light_spot10"}
		{view show "lamp_light_spot10"}
		{view start "lamp_light_spot11"}
		{view show "lamp_light_spot11"}
		{view start "lamp_light_spot12"}
		{view show "lamp_light_spot12"}
		{view show "lamp_light_spot13"}
	}
	{on "lights_off"
		{view stop "lamp_light_spot1"}
		{view hide "lamp_light_spot1"}
		{view stop "lamp_light_spot2"}
		{view hide "lamp_light_spot2"}
		{view stop "lamp_light_spot3"}
		{view hide "lamp_light_spot3"}
		{view stop "lamp_light_spot4"}
		{view hide "lamp_light_spot4"}
		{view hide "lamp_light_spot5"}
		{view hide "lamp_light_spot6"}
		{view hide "lamp_light_spot7"}
		{view hide "lamp_light_spot8"}
		{view hide "lamp_light_spot9"}
		{view hide "lamp_light_spot10"}
		{view hide "lamp_light_spot11"}
		{view hide "lamp_light_spot12"}
		{view stop "lamp_light_spot5"}
		{view stop "lamp_light_spot6"}
		{view stop "lamp_light_spot7"}
		{view stop "lamp_light_spot8"}
		{view stop "lamp_light_spot9"}
		{view stop "lamp_light_spot10"}
		{view stop "lamp_light_spot11"}
		{view stop "lamp_light_spot12"}
		{view stop "lamp_light_spot13"}
	}
	{on break_armor
		{if volume "lamp1"
			{view stop "lamp_light_spot1"}
			{view hide "lamp_light_spot1"}
		else volume "lamp2"
			{view stop "lamp_light_spot2"}
			{view hide "lamp_light_spot2"}
		else volume "lamp3"
			{view stop "lamp_light_spot3"}
			{view hide "lamp_light_spot3"}
		else volume "lamp4"
			{view stop "lamp_light_spot4"}
			{view hide "lamp_light_spot4"}
		else volume "lamp5"
			{view stop "lamp_light_spot5"}
			{view hide "lamp_light_spot5"}
		else volume "lamp6"
			{view stop "lamp_light_spot6"}
			{view hide "lamp_light_spot6"}
		else volume "lamp7"
			{view stop "lamp_light_spot7"}
			{view hide "lamp_light_spot7"}
		else volume "lamp8"
			{view stop "lamp_light_spot8"}
			{view hide "lamp_light_spot8"}
		else volume "lamp9"
			{view stop "lamp_light_spot9"}
			{view hide "lamp_light_spot9"}
		else volume "lamp10"
			{view stop "lamp_light_spot10"}
			{view hide "lamp_light_spot10"}
		else volume "lamp11"
			{view stop "lamp_light_spot11"}
			{view hide "lamp_light_spot11"}
		else volume "lamp12"
			{view stop "lamp_light_spot12"}
			{view hide "lamp_light_spot12"}
		else volume "lamp13"
			{view stop "lamp_light_spot13"}
			{view hide "lamp_light_spot13"}
		}
	}
}

{"lamp_spot"
	{on spawn
		{add_view 	"light_post_dir_add"		"lamp_light_spot1"			"lamp_light_spot1"}
		{add_view 	"light_post_dir_add"		"lamp_light_spot2"			"lamp_light_spot2"}
		{add_view 	"light_post_dir_add"		"lamp_light_spot3"			"lamp_light_spot3"}
		{add_view 	"light_post_dir_add"		"lamp_light_spot4"			"lamp_light_spot4"}
		{add_view 	"light_post_dir_add"		"lamp_light_spot5"			"lamp_light_spot5"}
		{add_view 	"light_post_dir_add"		"lamp_light_spot6"			"lamp_light_spot6"}
		{add_view 	"light_post_dir_add"		"lamp_light_spot7"			"lamp_light_spot7"}
		{add_view 	"light_post_dir_add"		"lamp_light_spot8"			"lamp_light_spot8"}
		{add_view 	"light_post_dir_add"		"lamp_light_spot9"			"lamp_light_spot9"}
		{add_view 	"light_post_dir_add"		"lamp_light_spot10"			"lamp_light_spot10"}
		{add_view 	"light_post_dir_add"		"lamp_light_spot11"			"lamp_light_spot11"}
		{add_view 	"light_post_dir_add"		"lamp_light_spot12"			"lamp_light_spot12"}
		{view hide "lamp_light_spot1"}
		{view hide "lamp_light_spot2"}
		{view hide "lamp_light_spot3"}
		{view hide "lamp_light_spot4"}
		{view hide "lamp_light_spot5"}
		{view hide "lamp_light_spot6"}
		{view hide "lamp_light_spot7"}
		{view hide "lamp_light_spot8"}
		{view hide "lamp_light_spot9"}
		{view hide "lamp_light_spot10"}
		{view hide "lamp_light_spot11"}
		{view hide "lamp_light_spot12"}
		{view hide "lamp_light_spot13"}
		{call "update_lights"}
	}
	{on "broken_power"
		{start_sound "hit/generic/metal_small/15/"}	
		{call "lights_off"}
		{delay 0.2
			{start_sound "hit/generic/metal_small/15/"}	
			{call "lights_on"}
			{delay 0.4
				{start_sound "hit/generic/metal_small/15/"}	
				{call "lights_off"}
			}
		}
	}
	{on "break"
		{view stop "lamp_light_spot1"}
		{view hide "lamp_light_spot1"}
		{view stop "lamp_light_spot2"}
		{view hide "lamp_light_spot2"}
		{view stop "lamp_light_spot3"}
		{view hide "lamp_light_spot3"}
		{view stop "lamp_light_spot4"}
		{view hide "lamp_light_spot4"}
	}
	{on "update_lights"
		{if not sunlight
			{call "lights_on"}
		else
			{call "lights_off"}
		}
	}
	{on "environment_changed"
		{call "update_lights"}
	}
	{on "lights_on"
		{view start "lamp_light_spot1"}
		{view show "lamp_light_spot1"}
		{view start "lamp_light_spot2"}
		{view show "lamp_light_spot2"}
		{view start "lamp_light_spot3"}
		{view show "lamp_light_spot3"}
		{view start "lamp_light_spot4"}
		{view show "lamp_light_spot4"}
		{view start "lamp_light_spot5"}
		{view show "lamp_light_spot5"}
		{view start "lamp_light_spot6"}
		{view show "lamp_light_spot6"}
		{view start "lamp_light_spot7"}
		{view show "lamp_light_spot7"}
		{view start "lamp_light_spot8"}
		{view show "lamp_light_spot8"}
		{view start "lamp_light_spot9"}
		{view show "lamp_light_spot9"}
		{view start "lamp_light_spot10"}
		{view show "lamp_light_spot10"}
		{view start "lamp_light_spot11"}
		{view show "lamp_light_spot11"}
		{view start "lamp_light_spot12"}
		{view show "lamp_light_spot12"}
		{view show "lamp_light_spot13"}
	}
	{on "lights_off"
		{view stop "lamp_light_spot1"}
		{view hide "lamp_light_spot1"}
		{view stop "lamp_light_spot2"}
		{view hide "lamp_light_spot2"}
		{view stop "lamp_light_spot3"}
		{view hide "lamp_light_spot3"}
		{view stop "lamp_light_spot4"}
		{view hide "lamp_light_spot4"}
		{view hide "lamp_light_spot5"}
		{view hide "lamp_light_spot6"}
		{view hide "lamp_light_spot7"}
		{view hide "lamp_light_spot8"}
		{view hide "lamp_light_spot9"}
		{view hide "lamp_light_spot10"}
		{view hide "lamp_light_spot11"}
		{view hide "lamp_light_spot12"}
		{view stop "lamp_light_spot5"}
		{view stop "lamp_light_spot6"}
		{view stop "lamp_light_spot7"}
		{view stop "lamp_light_spot8"}
		{view stop "lamp_light_spot9"}
		{view stop "lamp_light_spot10"}
		{view stop "lamp_light_spot11"}
		{view stop "lamp_light_spot12"}
		{view stop "lamp_light_spot13"}
	}
	{on break_armor
		{if volume "lamp1"
			{view stop "lamp_light_spot1"}
			{view hide "lamp_light_spot1"}
		else volume "lamp2"
			{view stop "lamp_light_spot2"}
			{view hide "lamp_light_spot2"}
		else volume "lamp3"
			{view stop "lamp_light_spot3"}
			{view hide "lamp_light_spot3"}
		else volume "lamp4"
			{view stop "lamp_light_spot4"}
			{view hide "lamp_light_spot4"}
		else volume "lamp5"
			{view stop "lamp_light_spot5"}
			{view hide "lamp_light_spot5"}
		else volume "lamp6"
			{view stop "lamp_light_spot6"}
			{view hide "lamp_light_spot6"}
		else volume "lamp7"
			{view stop "lamp_light_spot7"}
			{view hide "lamp_light_spot7"}
		else volume "lamp8"
			{view stop "lamp_light_spot8"}
			{view hide "lamp_light_spot8"}
		else volume "lamp9"
			{view stop "lamp_light_spot9"}
			{view hide "lamp_light_spot9"}
		else volume "lamp10"
			{view stop "lamp_light_spot10"}
			{view hide "lamp_light_spot10"}
		else volume "lamp11"
			{view stop "lamp_light_spot11"}
			{view hide "lamp_light_spot11"}
		else volume "lamp12"
			{view stop "lamp_light_spot12"}
			{view hide "lamp_light_spot12"}
		else volume "lamp13"
			{view stop "lamp_light_spot13"}
			{view hide "lamp_light_spot13"}
		}
	}
}

{"switched_lamp"
	{on spawn
		{add_view 	"headlight_car_dxo_long"			"lamp_light_spot1"			"lamp_light_spot1"}
		{add_view 	"headlight_car_dxo_long"			"lamp_light_spot2"			"lamp_light_spot2"}
		{add_view 	"light_post_dir_add"		"lamp_light_spot1"			"lamp_light_spot1"}
		{add_view 	"light_post_dir_add"		"lamp_light_spot2"			"lamp_light_spot2"}
		{add_view 	"light_post_dir_add"		"lamp_light_spot3"			"lamp_light_spot3"}
		{add_view 	"light_post_dir_add"		"lamp_light_spot4"			"lamp_light_spot4"}
		{add_view 	"light_post_dir_add"		"lamp_light_spot5"			"lamp_light_spot5"}
		{add_view 	"light_post_dir_add"		"lamp_light_spot6"			"lamp_light_spot6"}
		{add_view 	"light_post_dir_add"		"lamp_light_spot7"			"lamp_light_spot7"}
		{add_view 	"light_post_dir_add"		"lamp_light_spot8"			"lamp_light_spot8"}
		{add_view 	"light_post_dir_add"		"lamp_light_spot9"			"lamp_light_spot9"}
		{add_view 	"light_post_dir_add"		"lamp_light_spot10"			"lamp_light_spot10"}
		{add_view 	"light_post_dir_add"		"lamp_light_spot11"			"lamp_light_spot11"}
		{add_view 	"light_post_dir_add"		"lamp_light_spot12"			"lamp_light_spot12"}
		{view hide "lamp_light_spot1"}
		{view hide "lamp_light_spot2"}
		{view hide "lamp_light_spot3"}
		{view hide "lamp_light_spot4"}
		{view hide "lamp_light_spot5"}
		{view hide "lamp_light_spot6"}
		{view hide "lamp_light_spot7"}
		{view hide "lamp_light_spot8"}
		{view hide "lamp_light_spot9"}
		{view hide "lamp_light_spot10"}
		{view hide "lamp_light_spot11"}
		{view hide "lamp_light_spot12"}
		{view hide "lamp_light_spot13"}
		{call "update_lights"}
	}
	{on "broken_power"
		{start_sound "hit/generic/metal_small/15/"}	
		{call "lights_off"}
		{delay 0.2
			{start_sound "hit/generic/metal_small/15/"}	
			{call "lights_on"}
			{delay 0.4
				{start_sound "hit/generic/metal_small/15/"}	
				{call "lights_off"}
			}
		}
	}
	{on ground_hit
		{if contact_velocity 2
			{call "lights_off"}
		}
	}
	{on "break"
		{view stop "lamp_light_spot1"}
		{view hide "lamp_light_spot1"}
		{view stop "lamp_light_spot2"}
		{view hide "lamp_light_spot2"}
		{view stop "lamp_light_spot3"}
		{view hide "lamp_light_spot3"}
		{view stop "lamp_light_spot4"}
		{view hide "lamp_light_spot4"}
		{view stop "lamp_light_spot5"}
		{view hide "lamp_light_spot5"}
		{view stop "lamp_light_spot6"}
		{view hide "lamp_light_spot6"}
		{view stop "lamp_light_spot7"}
		{view hide "lamp_light_spot7"}
	}
	{on "update_lights"
		{if not sunlight
			{call "lights_on"}
		else
			{call "lights_off"}
		}
	}
	{on "environment_changed"
		{call "update_lights"}
	}
	{on "lights_on"	
		{tags add "lights_on" }
		;{view stop "lamps_off"}
		;{view hide "lamps_off"}
		{view stop "lamp_light_off2"}
		{view hide "lamp_light_off2"}
		{view stop "lamp_light_off1"}
		{view hide "lamp_light_off1"}	
		{view start "lamp_light_spot1"}
		{view show "lamp_light_spot1"}
		{view start "lamp_light_spot2"}
		{view show "lamp_light_spot2"}
		{view start "lamp_light_spot3"}
		{view show "lamp_light_spot3"}
		{view start "lamp_light_spot4"}
		{view show "lamp_light_spot4"}
		{view start "lamp_light_spot5"}
		{view show "lamp_light_spot5"}
		{view start "lamp_light_spot6"}
		{view show "lamp_light_spot6"}
		{view start "lamp_light_spot7"}
		{view show "lamp_light_spot7"}
		{view start "lamp_light_spot8"}
		{view show "lamp_light_spot8"}
		{view start "lamp_light_spot9"}
		{view show "lamp_light_spot9"}
		{view start "lamp_light_spot10"}
		{view show "lamp_light_spot10"}
		{view start "lamp_light_spot11"}
		{view show "lamp_light_spot11"}
		{view start "lamp_light_spot12"}
		{view show "lamp_light_spot12"}
		{view show "lamp_light_spot13"}
	}
	{on "lights_off"
		{tags remove "lights_on" }
		{view show "lamps_off"}
		{view start "lamps_off"}
		{view start "lamp_light_off1"}
		{view show "lamp_light_off1"}
		{view start "lamp_light_off2"}
		{view show "lamp_light_off2"}
		{view stop "lamp_light_spot1"}
		{view hide "lamp_light_spot1"}
		{view stop "lamp_light_spot2"}
		{view hide "lamp_light_spot2"}
		{view stop "lamp_light_spot3"}
		{view hide "lamp_light_spot3"}
		{view stop "lamp_light_spot4"}
		{view hide "lamp_light_spot4"}
		{view hide "lamp_light_spot5"}
		{view hide "lamp_light_spot6"}
		{view hide "lamp_light_spot7"}
		{view hide "lamp_light_spot8"}
		{view hide "lamp_light_spot9"}
		{view hide "lamp_light_spot10"}
		{view hide "lamp_light_spot11"}
		{view hide "lamp_light_spot12"}
		{view stop "lamp_light_spot5"}
		{view stop "lamp_light_spot6"}
		{view stop "lamp_light_spot7"}
		{view stop "lamp_light_spot8"}
		{view stop "lamp_light_spot9"}
		{view stop "lamp_light_spot10"}
		{view stop "lamp_light_spot11"}
		{view stop "lamp_light_spot12"}
		{view stop "lamp_light_spot13"}
	}
	{on bullet_hit
		{if volume "lamp1"
			{spawn "ex_lamps" "cable02"}
			{if tagged "lights_on" 
				{spawn "ex_lamps" "lamp_light_spot1"}
				{view stop "lamps_off"}
				{view hide "lamps_off"}
				{view stop "lamp_light_off1"}
				{view hide "lamp_light_off1"}
				{view stop "lamp_light_spot1"}
				{view hide "lamp_light_spot1"}
				{delay_ex 0.1 uniq
					{bone cut}
				}
			else
				{view stop "lamp_light_off1"}
				{view hide "lamp_light_off1"}
				{view stop "lamps_off"}
				{view hide "lamps_off"}
				{view stop "lamp_light_spot1"}
				{view hide "lamp_light_spot1"}
				{delay 0
					{spawn "ex_lamps" "lamp_light_off1"}
					{spawn "ex_lamps" "lamp_light_off"}
				}
				{delay_ex 0.1 uniq
					{bone cut}
				}
			}
		else volume "lamp2"
			{spawn "ex_lamps" "cable01"}
			{if tagged "lights_on" 
				{spawn "ex_lamps" "lamp_light_spot2"}
				{view stop "lamp_light_off2"}
				{view hide "lamp_light_off2"}
				{view stop "lamp_light_spot2"}
				{view hide "lamp_light_spot2"}
				{delay_ex 0.1 uniq
					{bone cut}
				}
			else
				{view stop "lamp_light_off2"}
				{view hide "lamp_light_off2"}
				{view stop "lamp_light_spot2"}
				{view hide "lamp_light_spot2"}
				{delay 0
					{spawn "ex_lamps" "lamp_light_off2"}
				}
				{delay_ex 0.1 uniq
					{bone cut}
				}
			}
		else volume "lamp3"
			{view stop "lamp_light_spot3"}
			{view hide "lamp_light_spot3"}
		else volume "lamp4"
			{view stop "lamp_light_spot4"}
			{view hide "lamp_light_spot4"}
		else volume "lamp5"
			{view stop "lamp_light_spot5"}
			{view hide "lamp_light_spot5"}
		else volume "lamp6"
			{view stop "lamp_light_spot6"}
			{view hide "lamp_light_spot6"}
		else volume "lamp7"
			{view stop "lamp_light_spot7"}
			{view hide "lamp_light_spot7"}
		else volume "lamp8"
			{view stop "lamp_light_spot8"}
			{view hide "lamp_light_spot8"}
		else volume "lamp9"
			{view stop "lamp_light_spot9"}
			{view hide "lamp_light_spot9"}
		else volume "lamp10"
			{view stop "lamp_light_spot10"}
			{view hide "lamp_light_spot10"}
		else volume "lamp11"
			{view stop "lamp_light_spot11"}
			{view hide "lamp_light_spot11"}
		else volume "lamp12"
			{view stop "lamp_light_spot12"}
			{view hide "lamp_light_spot12"}
		else volume "lamp13"
			{view stop "lamp_light_spot13"}
			{view hide "lamp_light_spot13"}
		}
	}
	{on blast
		{if volume "lamp1"
			{spawn "ex_lamps" "cable02"}
			{if tagged "lights_on" 
				{spawn "ex_lamps" "lamp_light_spot1"}
				{view stop "lamps_off"}
				{view hide "lamps_off"}
				{view stop "lamp_light_off1"}
				{view hide "lamp_light_off1"}
				{view stop "lamp_light_spot1"}
				{view hide "lamp_light_spot1"}
				{delay_ex 0.1 uniq
					{bone cut}
				}
			else
				{view stop "lamp_light_off1"}
				{view hide "lamp_light_off1"}
				{view stop "lamps_off"}
				{view hide "lamps_off"}
				{view stop "lamp_light_spot1"}
				{view hide "lamp_light_spot1"}
				{delay 0
					{spawn "ex_lamps" "lamp_light_off1"}
					{spawn "ex_lamps" "lamp_light_off"}
				}
				{delay_ex 0.1 uniq
					{bone cut}
				}
			}
		else volume "lamp2"
			{spawn "ex_lamps" "cable01"}
			{if tagged "lights_on" 
				{spawn "ex_lamps" "lamp_light_spot2"}
				{view stop "lamp_light_off2"}
				{view hide "lamp_light_off2"}
				{view stop "lamp_light_spot2"}
				{view hide "lamp_light_spot2"}
				{delay_ex 0.1 uniq
					{bone cut}
				}
			else
				{view stop "lamp_light_off2"}
				{view hide "lamp_light_off2"}
				{view stop "lamp_light_spot2"}
				{view hide "lamp_light_spot2"}
				{delay 0
					{spawn "ex_lamps" "lamp_light_off2"}
				}
				{delay_ex 0.1 uniq
					{bone cut}
				}
			}
		else volume "lamp3"
			{view stop "lamp_light_spot3"}
			{view hide "lamp_light_spot3"}
		else volume "lamp4"
			{view stop "lamp_light_spot4"}
			{view hide "lamp_light_spot4"}
		else volume "lamp5"
			{view stop "lamp_light_spot5"}
			{view hide "lamp_light_spot5"}
		else volume "lamp6"
			{view stop "lamp_light_spot6"}
			{view hide "lamp_light_spot6"}
		else volume "lamp7"
			{view stop "lamp_light_spot7"}
			{view hide "lamp_light_spot7"}
		else volume "lamp8"
			{view stop "lamp_light_spot8"}
			{view hide "lamp_light_spot8"}
		else volume "lamp9"
			{view stop "lamp_light_spot9"}
			{view hide "lamp_light_spot9"}
		else volume "lamp10"
			{view stop "lamp_light_spot10"}
			{view hide "lamp_light_spot10"}
		else volume "lamp11"
			{view stop "lamp_light_spot11"}
			{view hide "lamp_light_spot11"}
		else volume "lamp12"
			{view stop "lamp_light_spot12"}
			{view hide "lamp_light_spot12"}
		else volume "lamp13"
			{view stop "lamp_light_spot13"}
			{view hide "lamp_light_spot13"}
		}
	}
	{on "switch"
		{if not tagged "broken"
			{if not tagged "lights_on"
				{view start "lamp_light_spot1"}
				{view show "lamp_light_spot1"}
				{view start "lamp_light_spot2"}
				{view show "lamp_light_spot2"}
				{view start "lamp_light_spot3"}
				{view show "lamp_light_spot3"}
				{view start "lamp_light_spot4"}
				{view show "lamp_light_spot4"}
				{start_sound "weapon/equip/"}
				{tags add "lights_on"}
			else 
				{tags remove "lights_on" }
				{start_sound "weapon/equip/"}
				{view stop "lamp_light_spot1"}
				{view hide "lamp_light_spot1"}
				{view stop "lamp_light_spot2"}
				{view hide "lamp_light_spot2"}
				{view stop "lamp_light_spot3"}
				{view hide "lamp_light_spot3"}
				{view stop "lamp_light_spot4"}
				{view hide "lamp_light_spot4"}
			}
		}
	}
}

{"lamp_point"
	{on spawn
		{add_view 	"light_post_plafond"		"lamp_light_point1"			"lamp_light_point1"}
		{add_view 	"light_post_plafond"		"lamp_light_point2"			"lamp_light_point2"}
		{add_view 	"light_post_plafond"		"lamp_light_point3"			"lamp_light_point3"}
		{add_view 	"light_post_plafond"		"lamp_light_point3"			"lamp_light_point4"}
		{view hide "lamp_light_point1"}
		{view hide "lamp_light_point2"}
		{view hide "lamp_light_point3"}
		{view hide "lamp_light_point4"}
		{call "update_lights"}
	}
	{on "broken_power"
		{start_sound "hit/generic/metal_small/15/"}	
		{call "lights_off"}
		{delay 0.2
			{start_sound "hit/generic/metal_small/15/"}	
			{call "lights_on"}
			{delay 0.4
				{start_sound "hit/generic/metal_small/15/"}	
				{call "lights_off"}
			}
		}
	}
	{on "break"
		{view stop "lamp_light_spot1"}
		{view hide "lamp_light_spot1"}
		{view stop "lamp_light_spot2"}
		{view hide "lamp_light_spot2"}
		{view stop "lamp_light_spot3"}
		{view hide "lamp_light_spot3"}
		{view stop "lamp_light_spot4"}
		{view hide "lamp_light_spot4"}
	}
	{on "update_lights"
		{if not sunlight
			{call "lights_on"}
		else
			{call "lights_off"}
		}
	}
	{on "environment_changed"
		{call "update_lights"}
	}
	{on "lights_on"
		{view start "lamp_light_point1"}
		{view show "lamp_light_point1"}
		{view start "lamp_light_point2"}
		{view show "lamp_light_point2"}
		{view start "lamp_light_point3"}
		{view show "lamp_light_point3"}
		{view start "lamp_light_point4"}
		{view show "lamp_light_point4"}
	}
	{on "lights_off"
		{view stop "lamp_light_point1"}
		{view hide "lamp_light_point1"}
		{view stop "lamp_light_point2"}
		{view hide "lamp_light_point2"}
		{view stop "lamp_light_point3"}
		{view hide "lamp_light_point3"}
		{view stop "lamp_light_point4"}
		{view hide "lamp_light_point4"}
	}
	{on break_armor
		{if volume "lamp1"
			{view stop "lamp_light_point1"}
			{view hide "lamp_light_point1"}
		else volume "lamp2"
			{view stop "lamp_light_point2"}
			{view hide "lamp_light_point2"}
		else volume "lamp3"
			{view stop "lamp_light_point3"}
			{view hide "lamp_light_point3"}
		else volume "lamp4"
			{view stop "lamp_light_point4"}
			{view hide "lamp_light_point4"}
		}
	}
}


{"lamp_spot_ed"
	{on spawn
		{add_view 	"light_post_plafond"		"lamp_light_point1"			"lamp_glass1"}
		{add_view 	"light_post_plafond"		"lamp_light_point2"			"lamp_glass2"}
		{add_view 	"light_post_plafond"		"lamp_light_point3"			"lamp_glass3"}
		{add_view 	"light_post_plafond"		"lamp_light_point4"			"lamp_glass4"}
		{view hide "lamp_light_point1"}
		{view hide "lamp_light_point2"}
		{view hide "lamp_light_point3"}
		{view hide "lamp_light_point4"}
		{call "update_lights"}
	}
	{on "change_model"
		{view stop "lamp_light_spot1"}
		{view hide "lamp_light_spot1"}
		{view stop "lamp_light_spot2"}
		{view hide "lamp_light_spot2"}
		{view stop "lamp_light_spot3"}
		{view hide "lamp_light_spot3"}
		{view stop "lamp_light_spot4"}
		{view hide "lamp_light_spot4"}
	}
	{on "broken_power"
		{start_sound "hit/generic/metal_small/15/"}	
		{call "lights_off"}
		{delay 0.2
			{start_sound "hit/generic/metal_small/15/"}	
			{call "lights_on"}
			{delay 0.4
				{start_sound "hit/generic/metal_small/15/"}	
				{call "lights_off"}
			}
		}
	}
	{on "update_lights"
		{if not sunlight
			{call "lights_on"}
		else
			{call "lights_off"}
		}
	}
	{on "environment_changed"
		{call "update_lights"}
	}
	{on "lights_on"
		{view start "lamp_light_point1"}
		{view show "lamp_light_point1"}
		{view start "lamp_light_point2"}
		{view show "lamp_light_point2"}
		{view start "lamp_light_point3"}
		{view show "lamp_light_point3"}
		{view start "lamp_light_point4"}
		{view show "lamp_light_point4"}
	}
	{on "lights_off"
		{view stop "lamp_light_point1"}
		{view hide "lamp_light_point1"}
		{view stop "lamp_light_point2"}
		{view hide "lamp_light_point2"}
		{view stop "lamp_light_point3"}
		{view hide "lamp_light_point3"}
		{view stop "lamp_light_point4"}
		{view hide "lamp_light_point4"}
	}
	{on break_armor
		{if volume "lamp1"
			{view stop "lamp_light_point1"}
			{view hide "lamp_light_point1"}
		else volume "lamp2"
			{view stop "lamp_light_point2"}
			{view hide "lamp_light_point2"}
		else volume "lamp3"
			{view stop "lamp_light_point3"}
			{view hide "lamp_light_point3"}
		else volume "lamp4"
			{view stop "lamp_light_point4"}
			{view hide "lamp_light_point4"}
		}
	}
}


{"firewood"
	{inflammation_time 10}
	{on bullet_hit
		{if stuff "shell fg"
			{bullet_detonate}
		}
	}
	{on break_armor
		{call "break"}
	}
	{on contact sync
		{if can_crush
			{volumes disable contact}
			{call "break"}
		}
	}
	{on "break"
		{spawn "wood_crush_big" "root"}
		{delay 0.2 {delete}}
	}
	{on "burn_volume"
		{if not burned
			{if volume "body"
				{burn volume fx "smoke_dead_tree1" time 25 2 even_law}
				{delay 25 "break_delay" {call "break"}}
			}
		}
	}
}

{"stack"
	{inflammation_time 0.3}
	{on bullet_hit
		{if stuff "shell"
			{spawn "hay_hit_norm"}
		else stuff "bullet"
			{spawn "hay_hit_small2"}
		}
	}
	{on break_armor
		{set "crush" 0}
		{call "crush"}
	}
	{on contact sync
		{if can_crush
			{call "crush"}
		}
	}
	{on "crush"
		{volumes disable visible bullet contact blast}
		{call "crush_fx"}
		{delete}
	}
	{on "burn_volume"
		{if not burned
			{if volume "fire"
				{call "_burn"}
			}
		}
	}
	{on "_burn"
		{volumes disable visible bullet contact blast}
		{burn volume "body" fx "smoke_dead_norm" time 25 even_law}
		{burn volume "body" fx "smoke_dead_tree1" time 20 even_law}
		{tex_morph "burned" 14}
		{delay 20.0
			{spawn "burn_grass1"}
			{call "crush"}
		}
	}
	{on "crush_fx"
		{spawn "wheat_big" no_position}
		{if "crush"
			{spawn "hay_hit_fall" "fx_hayfall1"}
			{spawn "hay_hit_fall" "fx_hayfall2"}
			{spawn "hay_hit_fall" "fx_hayfall3"}
			{spawn "hay_hit_fall" "fx_hayfall4"}
		else
			{spawn "hay_hit_big" no_position}
			{spawn "hay_hit_big" "FX_haulm1"}
			{spawn "hay_hit_big" "FX_haulm2"}
		}
	}
}

{"stack tent"
	{on "crush_fx" overload}
	{on bullet_hit overload
		{if not under_water
			{if stuff "bullet"
				{spawn "spheredust_small_short"}
			else stuff "zenite"
				{spawn "spheredust_small_short"}
			else stuff "shell"
				{spawn "spheredust_small_short"}
			else stuff "mortar"
				{spawn "spheredust_small_short"}
			}
		}
	}
}

{"gate"
	{on spawn
		;@note: the interaction flags and skeleton state are saved only in game mode
		;		so if we need the gate state to be saved in editor we have to check for tag and wind the animation if needed
		{if tagged "opened"
			{set "opened" 1}
			{ani_wind "open" end}
		}
		{call "update_area"}
	}
	{on "switch"
		{if not "opened"
			{set "opened" 1}
			{ani_play "open" resume callback}
			{call "update_area"}
		else
			{set "opened" 0}
			{ani_play "open" -1 resume}
			{call "update_area"}
		}
	}
	{on "open"
		{if not "user_opened"
			{set "opened" 1}
			{ani_play "open" resume callback}
			{call "update_area"}
		}
	}
	{on "close"
		{if not "user_opened"
			{set "opened" 0}
			{ani_play "open" -1 resume}
			{call "update_area"}
		}
	}
	{on animation_end "open"
		{tags add "opened"}
	}
	{on "update_area"
		{if "opened"
			{area disable	"close"}
			{area enable	"left"}
			{area enable	"right"}
		else
			{area enable	"close"}
			{area disable	"left"}
			{area disable	"right"}
		}
	}
	{on "open_disable"
		{volumes "door_lock" disable touch}
	}
	{on "open_enable"
		{volumes "door_lock" enable touch}
	}
}

{"ferry"
	{on spawn
		{call "update_area"}
	}
	(define "update_area"
		{if "opened%0"
			{area disable	"close%0_%1"}
			{area enable	"left%0_%1"}
			{area enable	"right%0_%1"}

			{area disable	"close%0_%2"}
			{area disable	"left%0_%2"}
			{area disable	"right%0_%2"}
		else
			{area enable	"close%0_%1"}
			{area disable	"left%0_%1"}
			{area disable	"right%0_%1"}

			{area disable	"close%0_%2"}
			{area disable	"left%0_%2"}
			{area disable	"right%0_%2"}
		}
	)
	(define "door"
		{on "open%0"
			{set "opened%0" 1}
			{ani_play "open%0"}
			{call "update_area%0"}
		}
		{on "close%0"
			{set "opened%0" 0}
			{ani_play "close%0"}
			{call "update_area%0"}
		}
		{on "open_fast%0"
			{set "opened%0" 1}
			{ani_wind "open%0" end}
			{call "update_area%0"}
		}
		{on "close_fast%0"
			{set "opened%0" 0}
			{ani_wind "close%0" end}
			{call "update_area%0"}
		}
		{on "update_area%0"
			{if not "moved"
				("update_area" args %0 1 2)
				{area enable	"rectangle01"}
				{area enable	"rectangle02"}
				{area disable	"rectangle03"}
				{area disable	"rectangle04"}
			else
				("update_area" args %0 2 1)
				{area disable	"rectangle01"}
				{area disable	"rectangle02"}
				{area enable	"rectangle03"}
				{area enable	"rectangle04"}
			}
		}
	)
	("door" args 1)
	("door" args 2)
	{on "update_area"
		{call "update_area1"}
		{call "update_area2"}
	}
	{on "move_front"
		{set "moved" 1}
		{call "update_area"}
		{land off}
		{ani_play "move" callback}
	}
	{on "move_back"
		{set "moved" 0}
		{call "update_area"}
		{land off}
		{ani_play "move" -1 callback}
	}
	{on "update_land"
		{land off}
		{land on}
	}
	{on animation_end "move"
		{land on}
	}
}

{"tank_platform"
	{on "close"
		{land off}
		{ani_play "close1"}
		{ani_play "close2"}
	}
	{on "open"
		{land on}
		{ani_play "close1" -1}
		{ani_play "close2" -1}
	}

	{on "move"
		{ani_play "move"}	
	}
}

{"switch"
	{on "switch"
		{tags add "switch"}
	}
}
{"switch_doors"
	{on spawn
		{tags add "close"}
	}
	{on "switch"
		{if tagged "close" 
			{start_sound "push/ammobox/close/"}
			{tags remove "close"}
			{tags add "open"}
			{ani_play "switch" 0.4}
		else tagged "open" 
			{start_sound "push/ammobox/open/"}
			{tags add "close"}
			{ani_play "switch" -0.4}
			{tags remove "open"}
		}
	}
}

{"switch_doors_closed"
	{on spawn
		{tags add "close"}
	}
	{on "switch"
		{if tagged "close" 
			{start_sound "push/ammobox/close/"}
			{tags remove "close"}
			{tags add "open"}
			{ani_play "switch" 0.4}
		else tagged "open" 
			{start_sound "push/ammobox/open/"}
			{tags add "close"}
			{ani_play "switch" -0.4}
			{tags remove "open"}
		}
		{delay 5
			{if tagged "open" 
				{start_sound "push/ammobox/open/"}
				{tags add "close"}
				{ani_play "switch" -0.4}
				{tags remove "open"}
			}	
		}	
	}
}

{"gate door_big"
	{on "open"
		{start_sound "vehicle/engine/door"}
	}
	{on "close"
		{start_sound "vehicle/engine/door"}
	}
}

{"gate lock"
	{on "open"
;		{start_sound "vehicle/engine/door"}
		{volumes "attach" enable touch}
	}
	{on bullet_hit
		{if volume "lock"
			{if not "opened"
				{call "open"}
				{set "user_opened" 1}
				{delay_ex 0
					{tear "piece_small_steel" bone "lock"
						{impulse up -1 0.7 dir 2.5 0.3 no_position}
					}
				}
			}
		}
	}
}

{"sand_bag"
	{on bullet_hit
		{if stuff "bullet"
			{bullet_detonate}
		else stuff "zenite"
			{bullet_detonate}
		}
	}
	{on contact sync
		{if can_crush
			{volumes disable contact}
			{delay 0
				{call "crush"}
			}
		}
	}
	{on "crush"
		{if not "crushed"
			{set "crushed" 1}
			{set_skeleton "_x"}
			{ani_play "crush1" callback}
			{call "update_fx"}
			{call "effects"}
		}
	}
	{on animation_end "crush1"
		{ani_play "crush2"}
	}
}

{"sand_bag_small"
	{on break_armor
		{spawn "sandbags_crush"}
		{delete}
	}
	{on contact sync
		{if can_crush
			{volumes disable contact}
			{spawn "sandbags_crush"}
			{delete}
		}
	}
}

{"sand_bag_big"
	{on break_armor
		{spawn "sandbags_crush"}
		{delete}
	}
	{on contact sync
		{if can_crush
			{volumes disable contact}
			{spawn "sandbags_crush"}
			{delete}
		}
	}
}

{"showcase"
	{on "break_window"
		{area disable}
	}
}

{"fountain_small"
	{on spawn
		{add_view "drops_water_fountain" "water" "FX_water"}
		{add_view "drops_water_fountain" "water" "FX_water1"}
		{add_view "drops_water_fountain" "water" "FX_water2"}
		{add_view "drops_water_fountain" "water" "FX_water3"}
		{add_view "fountain_small" "water" "FX_water4"}
		{view start "water"}
	}
}

{"waterfall_big"
	{on spawn
		{add_view "waterfall_sm"	"wfall"	"FX_waterfall1"	}
		{add_view "waterfall_sm"	"wfall"	"FX_waterfall2"	}
		{add_view "waterfall_sm"	"wfall"	"FX_waterfall3"	}
		{add_view "waterfall_sm"	"wfall"	"FX_waterfall4"	}
		{add_view "waterfall_sm"	"wfall"	"FX_waterfall5"	}
		{add_view "waterfall_sm"	"wfall"	"FX_waterfall6"	}
		{add_view "waterfall_sm"	"wfall"	"FX_waterfall7"	}
		{view start "wfall"}
	}
}

{"steam_small"
	{on spawn
		{add_view "steam" "smoke" "FX_steam"}
		{view start "smoke"}
	}
}

{"steam_big"
	{on spawn
		{add_view "smoke_black" "smoke" "FX_steam"}
		{view start "smoke"}
	}
}

{"trench"
	{on blast
		{if volume "body"
			{if min_energy 3
				{call "break"}
			}
		}
	}
	{on "break"
		{if not "broken"
			{set "broken" 1}
			{tags add "crushed"}
			{call "disable_volumes"}
			{delay_ex 0
				{set_skeleton "_x"}
				{call "update_fx"}
				{set "first_stage" 1}
				{set "last_stage" 1}
				{call "effects"}
				{ani_play "crush"}
				{delay 0.1
					{update_visibility_patch}
				}
			}
		}
	}
}

{"sewer"
	{on spawn
		{call "update_area"}
		{ani_play "open"}
	}
	{on "update_area"
		{if "opened"
			{area enable "sewer"}
		else
			{area disable "sewer"}
		}
	}
	{on "open"
		{ani_play "open" +1 resume}
		{set "opened" 1}
		{call "update_area"}
	}
	{on "close"
		{ani_play "open" -1 resume}
		{set "opened" 0}
		{call "update_area"}
	}
}

{"delete_after_crush"
	{on "break"
		{delete}
	}
}

{"boat_trap"
	{on "open"
		{land off}
		{ani_wind "land" end}
		{ani_play "open"}
		{delay 0.1
			{land on}
			{area disable "left"}
			{area disable "right"}
		}
	}
	{on "close"
		{land off}
		{ani_wind "land" begin}
		{ani_play "open" -1}
		{delay 5
			{land on}
			{area enable "left"}
			{area enable "right"}
		}
	}
}

{"oiltower"
    {on spawn
        {call "add_fire"}
        {delay 1
            {view start "fx"}
        }
    }
	{on "add_fire" overload
		{add_view "smoke_fire_window"	"fx" "fx_fire"}
	}
}

{"test_pza"
	{on bullet_hit overload
		{spawn "pza"}
	}
}

{"animation"
	{on spawn
		{ani_play "animation" loop}
	}
}

{"animation2"
	{on spawn
		{ani_play "animation" loop}
		{ani_play "animation2" loop}
	}
}
