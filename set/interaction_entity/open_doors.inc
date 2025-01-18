{"open_doors"
	{on spawn
		{if tagged "opened"
			{tags add "opened" }
			{ani_wind "open" end}
		}
		{call "update_area"}
	}
	{on "open"
		{if not tagged "opened"
			{volumes "door_open" disable touch}
			{start_sound "push/container/open/"}
			{delay 3
				{volumes "door_open" enable touch}
			}
			{tags add "opened" }
			{ani_play "open"  resume callback}
			{call "update_area"}
		else
			{start_sound "push/container/close/"}
			{volumes "door_open" disable touch}
			{delay 3
				{volumes "door_open" enable touch}
			}
			{tags remove "opened" }
			{ani_play "open" -1 resume}
			{call "update_area"}
		}
	}
	{on animation_end "open"
		{tags add "opened"}
	}
	{on "update_area"
		{if tagged "opened"
			{area enable	"open"}
			{area disable	"close"}
		else not tagged "opened"
			{area disable	"open"}
			{area enable	"close"}
		}
	}
	{on "open_disable"
		{volumes "door_lock" disable touch}
	}
	{on "open_enable"
		{volumes "door_lock" enable touch}
	}
}

{"open_doors_wood"
	{on spawn
		{link_sound "door_loop_var1" "generation_zero/interaction/doors/door_wood_barn/door_wood_barn_moving_creak_loop_01"} ;
		{if tagged "opened"
			{tags add "opened" }
			{ani_wind "open" end}
		}
		{call "update_area"}
	}
	{on "door_wood_open"
		{if not tagged "opened"
			{tags add "opened" }
			{ani_play "open" }
		else
			{tags remove "opened" }
			{ani_play "close" }
		}
	}
	{on animation_event "door_start"
		{start_sound "generation_zero/interaction/doors/door_wood_barn/open"}
		{call "update_area"}
		{volumes "door_open" disable touch}
		{delay 0.2
			{play_sound "door_loop_var1" 1}
		}
	}
	{on animation_event "door_end"
		{call "update_area"}
		{volumes "door_open" enable touch}
		{stop_sound "door_loop_var1" }
		{start_sound "generation_zero/interaction/doors/door_wood_barn/close"}
	}
	{on "update_area"
		{if tagged "opened"
			{area enable	"open"}
			{area disable	"close"}
		else
			{area disable	"open"}
			{area enable	"close"}
		}
	}
}

{"opened"
	{on spawn
		{tags add "close"}
		{volumes "touch" disable touch}
	}
	{on "open"
		{if tagged "close" 
			{tags remove "close"}
			{tags add "open"}
			{ani_play "open" 0.4}
			{delay 1
				{volumes "touch" enable touch}
			}
		else tagged "open" 
			{tags add "close"}
			{ani_play "open" -0.7}
			{volumes "touch" disable touch}
			{tags remove "open"}
		}
	}
}
{"opened_small"
	{on spawn
		{tags add "close"}
		{volumes "touch" disable touch}
	}
	{on "open"
		{if tagged "close" 
			{tags remove "close"}
			{tags add "open"}
			{ani_play "open" 0.4}
			{delay 1
				{volumes "touch" enable touch}
			}
		else tagged "open" 
			{tags add "close"}
			{ani_play "open" -0.4}
			{volumes "touch" disable touch}
			{tags remove "open"}
		}
	}
}
{"opened_two"
	{on spawn
		{tags add "close"}
		{tags add "tools"}
		{volumes "touch" disable touch}
	}
	{on "open"
		{if tagged "close" 
			{tags remove "close"}
			{tags add "open"}
			{ani_play "open" 0.8}
			{ani_play "open00" 0.8}
			{ani_play "open01" 0.8}
			{delay 1
				{volumes "touch" enable touch}
			}
		else tagged "open" 
			{tags add "close"}
			{ani_play "open" -0.7}
			{ani_play "open00" -0.7}
			{ani_play "open01" -0.7}
			{volumes "touch" disable touch}
			{tags remove "open"}
		}
	}
}


{"opened_two_heavy"
	{on spawn
		{tags add "close_r"}
		{tags add "close_l"}
	}
	{on "door_r_open"
		{if tagged "close_r" 
			{tags remove "close_r"}
			{tags add "open_r"}
			{ani_play "open_door_r" 0.5}
			{volumes "door_r_open" disable touch}
			{delay 5
				{volumes "door_r_open" enable touch}
			}
		else tagged "open_r" 
			{tags add "close_r"}
			{ani_play "open_door_r" -0.5}
			{tags remove "open_r"}
			{volumes "door_r_open" disable touch}
			{delay 5
				{volumes "door_r_open" enable touch}
			}
		}
	}
	{on "door_l_open"
		{if tagged "close_l" 
			{tags remove "close_l"}
			{tags add "open_l"}
			{ani_play "open_door_l" 0.5}
			{volumes "door_l_open" disable touch}
			{delay 5
				{volumes "door_l_open" enable touch}
			}
		else tagged "open_l" 
			{tags add "close_l"}
			{ani_play "open_door_l" -0.5}
			{tags remove "open_l"}
			{volumes "door_l_open" disable touch}
			{delay 5
				{volumes "door_l_open" enable touch}
			}
		}
	}
}
{"opened_four_heavy"
	{on spawn
		{link_sound 	"open"			"vehicle/open_gun/loop"}
		(define "door_open" ;
			{if not tagged "small_blast_%tag" 
				{area disable "door_%tag_expl"}
			}
			{if tagged "open_%tag" 
				{ani_wind "open_door_%tag" end}
				{area enable	"door_%tag_open"}
				{area disable	"door_%tag_close"}
			else 
				{tags add "close_%tag"}
				{area disable	"door_%tag_open"}
				{area enable	"door_%tag_close"}
			}
		)
		("door_open" tag(rt) )
		("door_open" tag(lt) )
		("door_open" tag(rf) )
		("door_open" tag(lf) )
	}
	(define "door_open" 
		{on animation_end "open_door_%tag"
			{stop_sound "open" }
			{start_sound "push/container/close/"}
			{tags add "open_%tag"}
		}
	)
	("door_open" tag(rt) )
	("door_open" tag(lt) )
	("door_open" tag(rf) )
	("door_open" tag(lf) )
	{on "update_area"
		(define "door_open" ;
			{if tagged "close_%tag" 
				{area disable	"door_%tag_open"}
				{area enable	"door_%tag_close"}
			else 
				{area enable	"door_%tag_open"}
				{area disable	"door_%tag_close"}
			}
		)
		("door_open" tag(rt) )
		("door_open" tag(lt) )
		("door_open" tag(rf) )
		("door_open" tag(lf) )
	}
	(define "door_open" ;door_lf_open
		{on "door_%tag_open"
			{if tagged "close_%tag" 
				{play_sound "open" 1}
				{start_sound "push/container/open/"}
				{tags remove "close_%tag"}			
				{ani_play "open_door_%tag" +1.0 resume callback}
				;{volumes "door_%tag_open" disable touch}
				{delay 2.5
					{area enable	"door_%tag_open"}
					{area disable	"door_%tag_close"}
				}
			else 
				{start_sound "push/container/close/"}
				{ani_play "open_door_%tag" -1 resume }
				{tags remove "open_%tag"}
				{tags add "close_%tag"}
				;{volumes "door_%tag_open" disable touch}
				{delay 2.5
					{area disable	"door_%tag_open"}
					{area enable	"door_%tag_close"}
				}
			}
		}
	)
	("door_open" tag(rt) )
	("door_open" tag(lt) )
	("door_open" tag(rf) )
	("door_open" tag(lf) )
}






{"opened_dealer"
	{on spawn
		{link_sound 	"open"			"vehicle/open_gun/loop"}
		(define "door_open" ;
			{if tagged "open_%tag" 
				{ani_wind "open_door_%tag" end}
				{area enable	"door_%tag_open"}
				{area disable	"door_%tag_close"}
			else 
				{tags add "close_%tag"}
				{area disable	"door_%tag_open"}
				{area enable	"door_%tag_close"}
			}
		)
		("door_open" tag(garage) )
		("door_open" tag(wood) )
		("door_open" tag(small) )
	}
	(define "door_open" 
		{on animation_end "open_door_%tag"
			;{stop_sound "open" }
			;{start_sound "push/container/close/"}
			{tags add "open_%tag"}
		}
	)
	("door_open" tag(garage) )
	("door_open" tag(wood) )
	("door_open" tag(small) )
	{on "update_area"
		(define "door_open" ;
			{if tagged "close_%tag" 
				{area disable	"door_%tag_open"}
				{area enable	"door_%tag_close"}
			else 
				{area enable	"door_%tag_open"}
				{area disable	"door_%tag_close"}
			}
		)
		("door_open" tag(garage) )
		("door_open" tag(wood) )
		("door_open" tag(small) )
	}
	(define "door_open" ;door_lf_open
		{on "door_%tag_open"
			{if tagged "close_%tag" 
				;{play_sound "open" 1}
				{start_sound "push/container/open/"}
				{tags remove "close_%tag"}			
				{ani_play "open_door_%tag" +1.0 resume callback}
				;{volumes "door_%tag_open" disable touch}
				{delay 2.5
					{area enable	"door_%tag_open"}
					{area disable	"door_%tag_close"}
				}
			else 
				;{start_sound "push/container/close/"}
				{ani_play "open_door_%tag" -1 resume }
				{tags remove "open_%tag"}
				{tags add "close_%tag"}
				;{volumes "door_%tag_open" disable touch}
				{delay 2.5
					{area disable	"door_%tag_open"}
					{area enable	"door_%tag_close"}
				}
			}
		}
	)
	("door_open" tag(garage) )
	("door_open" tag(wood) )
	("door_open" tag(small) )
}


{"container_locker"
	{on "open"
		{if tagged "open" 
			{start_sound "push/container/close/"}
		else tagged "close" 
			{start_sound "push/container/open/"}
		}
	}
}

{"big_locker"
	{on "open"
		{if tagged "open" 
			{start_sound "push/metal_hatch/close/"}
		else tagged "close" 
			{start_sound "push/metal_hatch/open/"}
		}
	}
}
{"cabgar01_locker"
	{on "open"
		{if tagged "open" 
			{start_sound "push/cabinetgarage01/close/"}
		else tagged "close" 
			{start_sound "push/cabinetgarage01/open/"}
		}
	}
}
{"cabgar02_locker"
	{on "open"
		{if tagged "open" 
			{start_sound "push/cabinetgarage02/close/"}
		else tagged "close" 
			{start_sound "push/cabinetgarage02/open/"}
		}
	}
}
{"cabgar03_locker"
	{on "open"
		{if tagged "open" 
			{start_sound "push/cabinetgarage03/close/"}
		else tagged "close" 
			{start_sound "push/cabinetgarage03/open/"}
		}
	}
}
{"cabgar04_locker"
	{on "open"
		{if tagged "open" 
			{start_sound "push/cabinetgarage04/close/"}
		else tagged "close" 
			{start_sound "push/cabinetgarage04/open/"}
		}
	}
}
{"cabgar05_locker"
	{on "open"
		{if tagged "open" 
			{start_sound "push/cabinetgarage05/close/"}
		else tagged "close" 
			{start_sound "push/cabinetgarage05/open/"}
		}
	}
}
{"small_locker"
	{on "open"
		{if tagged "open" 
			{start_sound "push/metal_hatch/close/"}
		else tagged "close" 
			{start_sound "push/metal_hatch/open/"}
		}
	}
}
{"foot_locker"
	{on "open"
		{if tagged "open" 
			{start_sound "push/footlocker/close/"}
		else tagged "close" 
			{start_sound "push/footlocker/open/"}
		}
	}
}
{"toolcase_locker"
	{on "open"
		{if tagged "open" 
			{start_sound "push/toolcase/close/"}
		else tagged "close" 
			{start_sound "push/toolcase/open/"}
		}
	}
}
{"toolbox_locker"
	{on "open"
		{if tagged "open" 
			{start_sound "push/toolbox/close/"}
		else tagged "close" 
			{start_sound "push/toolbox/open/"}
		}
	}
}
{"ammobox_locker"
	{on "open"
		{if tagged "open" 
			{start_sound "push/ammobox/close/"}
		else tagged "close" 
			{start_sound "push/ammobox/open/"}
		}
	}
}
{"metal_locker"
	{on "open"
		{if tagged "open" 
			{start_sound "push/metallocker/close/"}
		else tagged "close" 
			{start_sound "push/metallocker/open/"}
		}
	}
}
{"safesmall"
	{on spawn
		;{set "armor" 1}
	}
	{on "open"
		{if tagged "open" 
			{start_sound "push/safecontainer/close/"}
		else tagged "close" 
			{start_sound "push/safecontainer/open/"}
		}
	}
	{on contact
		{if effector "fraction_small" ;дробь
			{if contact_velocity 2
				(define "cut_part"
					{if rand %2
						{if volume %1
							{tear "piece_small_steel" bone %0
								{impulse up 4 1 dir 2 1}
							}
						}
					}
				)		
				("cut_part" args "low_lockpiece"	 		"low_lockpiece"		0.1)
				("cut_part" args "dial01"	 		"dial01"		0.1)
				("cut_part" args "dial02"	 		"dial02"		0.1)
				("cut_part" args "door"			"door"		0.01)
				("cut_part" args "whell"		"whell"		0.1)
			}
		else effector "vehicle" 
			{if contact_velocity 2
				(define "cut_part"
					{if rand %2
						{if volume %1
							{tear "piece_small_steel" bone %0
								{impulse up 4 1 dir 2 1}
							}
						}
					}
				)	
				("cut_part" args "low_lockpiece"	 		"low_lockpiece"		0.1)
				("cut_part" args "dial01"	 		"dial01"		0.1)
				("cut_part" args "dial02"	 		"dial02"		0.1)
				("cut_part" args "door"			"door"		0.1)
				("cut_part" args "whell"		"whell"		0.1)
			}
		}
	}
	{on blast_hit
		{if rand 0.001 
			{spawn "ex_inc_small" "whell"}
			{volumes enable touch select}
		}
		(define "cut_part"
			{if rand %2
				{if volume %1
					{tear "piece_small_steel" bone %0
						{impulse up 4 1 dir 2 1}
					}
				}
			}
		)	
		("cut_part" args "low_lockpiece"	 		"low_lockpiece"		0.1)
		("cut_part" args "dial01"	 		"dial01"		0.1)
		("cut_part" args "dial02"	 		"dial02"	0.1)
		("cut_part" args "door"			"door"		0.02)
		("cut_part" args "whell"		"whell"		0.1)
	}
	{on bullet_hit
		{if rand 0.001 
			{spawn "ex_inc_small" "whell"}
			{volumes enable touch select}
		}
		{if stuff "bullet"
			(define "cut_part"
				{if rand %2
					{if volume %1
						{tear "piece_small_steel" bone %0
							{impulse up 0.5 0.1 dir 0.5 0.1}
						}
					}
				}
			)	
			("cut_part" args "low_lockpiece"	 		"low_lockpiece"		0.1)
			("cut_part" args "dial01"		"dial01"		0.1)
			("cut_part" args "dial02"		"dial02"		0.1)
			("cut_part" args "door"		"door"		0.1)
			("cut_part" args "whell"		"whell"		0.1)
		}
	}
}

