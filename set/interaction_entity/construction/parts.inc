(define "cut_pieces"
	("cut_piece" args 0)	("cut_piece" args 1)
	("cut_piece" args 2)	("cut_piece" args 3)
	("cut_piece" args 4)	("cut_piece" args 5)
	("cut_piece" args 6)	("cut_piece" args 7)
	("cut_piece" args 8)	("cut_piece" args 9)
	("cut_piece" args 00)	("cut_piece" args 01)
	("cut_piece" args 02)	("cut_piece" args 03)
	("cut_piece" args 04)	("cut_piece" args 05)
	("cut_piece" args 06)	("cut_piece" args 07)
	("cut_piece" args 08)	("cut_piece" args 09)
	("cut_piece" args 10)	("cut_piece" args 11)
	("cut_piece" args 12)	("cut_piece" args 13)
	("cut_piece" args 14)	("cut_piece" args 15)
	("cut_piece" args 16)	("cut_piece" args 17)
	("cut_piece" args 18)	("cut_piece" args 19)
	("cut_piece" args 20)
)

(define "cut_subpieces"
	("cut_subpiece" args 0)	("cut_subpiece" args 1)
	("cut_subpiece" args 2)	("cut_subpiece" args 3)
	("cut_subpiece" args 4)	("cut_subpiece" args 5)
	("cut_subpiece" args 6)	("cut_subpiece" args 7)
	("cut_subpiece" args 8)	("cut_subpiece" args 9)
	("cut_subpiece" args 00)("cut_subpiece" args 01)
	("cut_subpiece" args 02)("cut_subpiece" args 03)
	("cut_subpiece" args 04)("cut_subpiece" args 05)
	("cut_subpiece" args 06)("cut_subpiece" args 07)
	("cut_subpiece" args 08)("cut_subpiece" args 09)
	("cut_subpiece" args 10)("cut_subpiece" args 11)
	("cut_subpiece" args 12)("cut_subpiece" args 13)
	("cut_subpiece" args 14)("cut_subpiece" args 15)
	("cut_subpiece" args 16)("cut_subpiece" args 17)
)

{"parts construction"
	{on break_armor
		{if volume "body"
			{if name "blast"
				{set "blast" 1}
				{if not "blast_disable"
					{if min_energy 350
						{set "blast_one" 0}
					else min_energy 10
						{set "blast_one" 1}
					}
					{call "change_model"}
				}
			; else stuff "zenite"
				; {if rand 0.2
					; {burn volume fx "rex_emitters_construction" time 0.1 fake even_law}
				; }
			; else stuff "bullet big"
				; {if rand 0.2
					; {burn volume fx "rex_emitters_construction" time 0.1 fake even_law}
				; }
			else stuff "bullet stackable"
			else
				{set "blast" 0}
				{call "change_model"}
			}
		}
	}
	{on bullet_hit
		{if volume "body"
			{if stuff "shell"
				{call "break_windows"}
			}
		}
	}
	{on contact sync
		{set "blast" 0}
		{if effector "airborne"
			{call "change_model"}
		else effector "air_part"
			{if min_speed 5
				{call "change_model"}
			}
		}
	}
	{on "change_model"
		{if not "sliced"
			{tags add "crushed"}
			{set "sliced" 1}
			{call "disable_volumes"}
			{call "check_structure"}
			{delay_ex 0.1
				{call "set_skeleton"}
				{call "disable_volumes"}
				{call "update_fx"}
				{set "first_stage" 1}
				{set "last_stage" 1}
				{call "effects"}
				{call "cut_pieces"}
				{ani_play "crush"}
				{delay 0.1
					{volumes "body" enable contact bullet blast visible}
					{restore_volume_states} ; restore volume ables from .def file
					{update_visibility_patch}
				}
			}
		}
	}
	{on "set_skeleton"
		{if not "x_skeleton_set"
			{set_skeleton "_x"}
			{set "sliced" 0}
			{set "x_skeleton_set" 1}
		else
			{set_skeleton "_xx"}
		}
	}
	{on "break"
		{call "change_model"}
	}
	{on "burn_end"
		{bone hide "roof_hide"}
		{tex_mod "burned"}
	}
}

{"break_on_burn parts construction"
	{on "burn_end"
		{call "break"}
	}
}

{"small parts construction"
	{on contact sync
		{set "blast" 0}
		{if can_crush
			{call "change_model"}
		}
	}
}




{"metals_build_gate"
	{on pierce sync
		{if stuff "shell"
			(define "cut_part"
				{if rand %2
					{if volume %1
						{tear "piece_medium_steel_crushed" bone %0
							{spawn "metal_crush" %0}
							{impulse up 1 0.5 dir 1 0.5}
						}
					else volume "frame"
						{set "end_stage" 1}
						{call "end_stage"}		
					else volume "frame0a"
						{set "end_stage" 1}
						{call "end_stage0a"}		
					}
				}
			)	
			("cut_part" args "rods00a"		"rods00a"			0.2)
			("cut_part" args "rods00"		"rods00"			0.2)
			("cut_part" args "parts00"		"parts00"			0.4)
			("cut_part" args "parts00a"		"parts00a"			0.4)
		else stuff "fx_40"
			(define "cut_part"
				{if rand %2
					{if volume %1
						{tear "piece_medium_steel_crushed" bone %0
							{spawn "metal_crush" %0}
							{impulse up 3 0.5 dir 1 0.5}
						}
					else volume "frame"
						{set "end_stage" 1}
						{call "end_stage"}		
					else volume "frame0a"
						{set "end_stage" 1}
						{call "end_stage0a"}		
					}
				}
			)	
			("cut_part" args "rods00a"		"rods00a"			0.9)
			("cut_part" args "rods00"		"rods00"			0.9)
			("cut_part" args "parts00"		"parts00"			0.9)
			("cut_part" args "parts00a"		"parts00a"			0.9)
		else stuff "bullet"
			(define "cut_part"
				{if rand %2
					{if volume %1
						{tear "piece_medium_steel_crushed" bone %0
							{spawn "metal_crush" %0}
							{impulse up 1 0.5 dir 1 0.5}
						}
					else volume "frame"
						{set "end_stage" 1}
						{call "end_stage"}		
					else volume "frame0a"
						{set "end_stage" 1}
						{call "end_stage0a"}		
					}
				}
			)	
			("cut_part" args "rods00a"		"rods00a"			0.9)
			("cut_part" args "rods00"		"rods00"			0.9)
			("cut_part" args "parts00"		"parts00"			0.9)
			("cut_part" args "parts00a"		"parts00a"			0.9)
		}
	}
	{on contact sync
		{if effector "fraction" 
			{if contact_velocity 1
				(define "cut_part"
					{if rand %2
						{if volume %1
							{tear "piece_medium_steel_crushed" bone %0
								{impulse up 2 1 dir 2 1}
							}
						}
					}
				)	
				("cut_part" args "rods00a"		"rods00a"			0.01)
				("cut_part" args "rods00"		"rods00"			0.01))
				("cut_part" args "parts00"		"parts00"			0.1)
				("cut_part" args "parts00a"		"parts00a"			0.1)
			}	
		else effector "tank" 
				(define "cut_part"
					{if volume %1
						{tear "piece_medium_steel_crushed" bone %0
							{impulse up 5 1 dir 2 1}
						}
					}
				)	
				("cut_part" args "rods00a"		"rods00a"				)
				("cut_part" args "rods00"		"rods00"				)
				("cut_part" args "parts00"		"parts00"				)
				("cut_part" args "parts00a"		"parts00a"				)
		else effector "vehicle" 
			{if contact_velocity 25
				(define "cut_part"
					{if volume %1
						{tear "piece_medium_steel_crushed" bone %0
							{impulse up 12 1 dir 6 1}
						}
					}
				)	
				("cut_part" args "rods00a"		"rods00a"				)
				("cut_part" args "rods00"		"rods00"				)
				("cut_part" args "parts00"		"parts00"				)
				("cut_part" args "parts00a"		"parts00a"				)
			else contact_velocity 15
				(define "cut_part"
					{if rand %2
						{if volume %1
							{tear "piece_medium_steel_crushed" bone %0
								{impulse up 2 1 dir 2 1}
							}
						}
					}
				)	
				("cut_part" args "rods00a"		"rods00a"			0.01)
				("cut_part" args "rods00"		"rods00"			0.01))
				("cut_part" args "parts00"		"parts00"			0.1)
				("cut_part" args "parts00a"		"parts00a"			0.1)
			else contact_velocity 5
				(define "cut_part"
					{if rand %2
						{if volume %1
							{tear "piece_medium_steel_crushed" bone %0
								{impulse up 2 1 dir 2 1}
							}
						}
					}
				)	
				("cut_part" args "rods00a"		"rods00a"			0.01)
				("cut_part" args "rods00"		"rods00"			0.01))
				("cut_part" args "parts00"		"parts00"			0.1)
				("cut_part" args "parts00a"		"parts00a"			0.1)
			}
		}
	}
	{on blast_hit
		{if min_energy 12
			(define "cut_part"
				{tear "piece_medium_steel_crushed" bone %0
					{impulse up 5 3 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
				}
			)
			("cut_part" args "steel00"				)
			("cut_part" args "parts00"				)
			("cut_part" args "rods00"				)
			("cut_part" args "stolb00"				)
		else min_energy 4
			(define "cut_part"
				{if rand %2
					{if volume %1
						{tear "piece_medium_steel_crushed" bone %0
							{impulse up 3 2 dir 3 1}
						}
					}
				}
			)	
			("cut_part" args "rods00a"		"rods00a"			0.1)
			("cut_part" args "rods00"		"rods00"			0.1))
			("cut_part" args "parts00"		"parts00"			0.2)
			("cut_part" args "parts00a"		"parts00a"			0.2)
		else min_energy 2
			(define "cut_part"
				{if rand %2
					{if volume %1
						{tear "piece_medium_steel_crushed" bone %0
							{impulse up 4 2 dir 6 1}
						}
					}
				}
			)	
			("cut_part" args "rods00a"		"rods00a"			0.01)
			("cut_part" args "rods00"		"rods00"			0.01))
			("cut_part" args "parts00"		"parts00"			0.1)
			("cut_part" args "parts00a"		"parts00a"			0.1)
		}
	}
	{on bullet_hit
		{if stuff "bullet"
			(define "cut_part"
				{if rand %2
					{if volume %1
						{tear "piece_small_steel" bone %0
							{impulse up 0.5 dir 0.1}
						}
					}
				}
			)	
			("cut_part" args "parts00"		"parts00"			0.1)
			("cut_part" args "parts00a"		"parts00a"			0.1)
		}
	}
	{on "end_stage"
		{if "end_stage"
			(define "cut_part"
				{tear "piece_small_steel" bone %0
					{impulse up 0.4 dir 0.1}
				}
			)			
			("cut_part" args "steel00"				)
			("cut_part" args "parts00"				)
			("cut_part" args "rods00"				)
			("cut_part" args "stolb00"				)
		}
	}
	{on "end_stage0a"
		{if "end_stage"
			(define "cut_part"
				{tear "piece_small_steel" bone %0
					{impulse up 0.4 dir 0.1}
				}
			)	
			("cut_part" args "steel00a"				)
			("cut_part" args "parts00a"				)
			("cut_part" args "rods00a"				)
			("cut_part" args "stolb00a"				)
		}
	}
}

{"metals_build"
	{on spawn
		{call "reset"}
	}
	{on "reset"
		(define "reset"
			{if tagged "hit_plank_bm_%0"
				{ani_play "hit_plank_bm_%0" 1}
			}
			{if tagged "hit_plank_bs_%0" 
				{ani_play "hit_plank_bs_%0" 1}
			}
			{if tagged "hit_plank_b_%0"
				{ani_play "hit_plank_s_%0" 1}
			}
			{if tagged "hit_plank_m_%0" 
				{ani_play "hit_plank_b_%0" 1}
			}
			{if tagged "hit_plank_s_%0" 
				{ani_play "hit_plank_s_%0" 1}
			else
				{ani_play "hit_plank_s_%0" -2}				
			}
		)	
		("reset" args plank00)
		("reset" args plank01)
		("reset" args plank02)
		("reset" args plank03)
		("reset" args plank04)
		("reset" args plank05)
		("reset" args plank06)
		("reset" args plank07)
		("reset" args plank08)
		("reset" args plank09)
		("reset" args plank10)
		("reset" args plank11)
		("reset" args plank12)
		("reset" args plank13)
		("reset" args plank14)
		("reset" args plank15)
		("reset" args plank16)
		("reset" args plank17)
		("reset" args plank18)
		("reset" args plank19)
		("reset" args steel00)
		("reset" args steel01)
		("reset" args steel02)
		("reset" args steel03)
		("reset" args steel04)
		("reset" args steel05)
		("reset" args steel06)
		("reset" args steel07)
		("reset" args steel08)
		("reset" args steel09)
		("reset" args steel10)
		("reset" args steel11)
		("reset" args steel12)
		("reset" args steel13)
		("reset" args steel14)
		("reset" args steel15)
		("reset" args steel16)
		("reset" args steel17)
		("reset" args steel18)
		("reset" args steel19)
		("reset" args iron_sheet00)
		("reset" args iron_sheet01)
		("reset" args iron_sheet02)
		("reset" args iron_sheet03)
		("reset" args iron_sheet04)
		("reset" args iron_sheet05)
		("reset" args iron_sheet06)
		("reset" args iron_sheet07)
		("reset" args iron_sheet08)
		("reset" args iron_sheet09)
		("reset" args iron_sheet10)
		("reset" args iron_sheet11)
		("reset" args iron_sheet12)
		("reset" args iron_sheet13)
		("reset" args iron_sheet14)
		("reset" args iron_sheet15)
		("reset" args iron_sheet16)
		("reset" args iron_sheet17)
		("reset" args iron_sheet18)
		("reset" args iron_sheet19)
		("reset" args iron_sheet20)
		("reset" args iron_sheet21)
		("reset" args iron_sheet22)
		("reset" args iron_sheet23)
		("reset" args iron_sheet24)
		("reset" args iron_sheet25)
		("reset" args iron_sheet26)
		("reset" args iron_sheet27)
		("reset" args iron_sheet28)
		("reset" args iron_sheet29)
		("reset" args iron_sheet30)
		("reset" args iron_sheet31)
		("reset" args iron_sheet32)
		("reset" args iron_sheet33)
		("reset" args iron_sheet34)
		("reset" args iron_sheet35)
		("reset" args iron_sheet36)
		("reset" args iron_sheet37)
		("reset" args iron_sheet38)
		("reset" args iron_sheet39)
	}
	{on pierce
		{if stuff "shell"
			(define "cut_part"
				{if rand %2
					{if volume %1
						{tear "piece_medium_steel_crushed" bone %0
							{spawn "metal_crush" %0}
							{impulse up 2 0.5 dir 2 0.5}
						}
					else volume "frame"
						{if rand 0.0001
							{set "end_stage" 1}
							{call "end_stage"}
						}
					}
				}
			)	
			("cut_part" args "plank00"		"plank00"			0.9)
			("cut_part" args "plank01"		"plank01"			0.9)
			("cut_part" args "plank02"		"plank02"			0.9)
			("cut_part" args "plank03"		"plank03"			0.9)
			("cut_part" args "plank04"		"plank04"			0.9)
			("cut_part" args "plank05"		"plank05"			0.9)
			("cut_part" args "plank06"		"plank06"			0.9)
			("cut_part" args "plank07"		"plank07"			0.9)
			("cut_part" args "plank08"		"plank08"			0.9)
			("cut_part" args "plank09"		"plank09"			0.9)
			("cut_part" args "plank10"		"plank10"			0.9)
			("cut_part" args "plank11"		"plank11"			0.9)
			("cut_part" args "plank12"		"plank12"			0.9)
			("cut_part" args "plank13"		"plank13"			0.9)
			("cut_part" args "steel00"		"steel00"			0.9)
			("cut_part" args "steel01"		"steel01"			0.9)
			("cut_part" args "steel02"		"steel02"			0.9)
			("cut_part" args "steel03"		"steel03"			0.9)
			("cut_part" args "steel04"		"steel04"			0.9)
			("cut_part" args "steel05"		"steel05"			0.9)
			("cut_part" args "steel06"		"steel06"			0.9)
			("cut_part" args "steel07"		"steel07"			0.9)
			("cut_part" args "steel08"		"steel08"			0.9)
			("cut_part" args "steel09"		"steel09"			0.9)
			("cut_part" args "steel10"		"steel10"			0.9)
			("cut_part" args "steel11"		"steel11"			0.9)
			("cut_part" args "steel12"		"steel12"			0.9)
			("cut_part" args "steel13"		"steel13"			0.9)
			("cut_part" args "steel14"		"steel14"			0.9)
			("cut_part" args "steel15"		"steel15"			0.9)
			("cut_part" args "steel16"		"steel16"			0.9)
			("cut_part" args "steel17"		"steel17"			0.9)
			("cut_part" args "steel18"		"steel18"			0.9)
			("cut_part" args "steel19"		"steel19"			0.9)
			("cut_part" args "steel20"		"steel20"			0.9)
			("cut_part" args "steel21"		"steel21"			0.9)
			("cut_part" args "steel22"		"steel22"			0.9)
			("cut_part" args "steel23"		"steel23"			0.9)
			("cut_part" args "steel24"		"steel24"			0.9)
			("cut_part" args "steel25"		"steel25"			0.9)
			("cut_part" args "steel26"		"steel26"			0.9)
			("cut_part" args "steel27"		"steel27"			0.9)
			("cut_part" args "steel28"		"steel28"			0.9)
			("cut_part" args "steel29"		"steel29"			0.9)
			("cut_part" args "steel30"		"steel30"			0.9)
			("cut_part" args "steel31"		"steel31"			0.9)
			("cut_part" args "steel32"		"steel32"			0.9)
			("cut_part" args "steel33"		"steel33"			0.9)
			("cut_part" args "iron_sheet00"		"iron_sheet00"			0.9)
			("cut_part" args "iron_sheet01"		"iron_sheet01"			0.9)
			("cut_part" args "iron_sheet02"		"iron_sheet02"			0.9)
			("cut_part" args "iron_sheet03"		"iron_sheet03"			0.9)
			("cut_part" args "iron_sheet04"		"iron_sheet04"			0.9)
			("cut_part" args "iron_sheet05"		"iron_sheet05"			0.9)
			("cut_part" args "iron_sheet06"		"iron_sheet06"			0.9)
			("cut_part" args "iron_sheet07"		"iron_sheet07"			0.9)
			("cut_part" args "iron_sheet08"		"iron_sheet08"			0.9)
			("cut_part" args "iron_sheet09"		"iron_sheet09"			0.9)
			("cut_part" args "iron_sheet10"		"iron_sheet10"			0.9)
			("cut_part" args "iron_sheet11"		"iron_sheet11"			0.9)
			("cut_part" args "iron_sheet12"		"iron_sheet12"			0.9)
			("cut_part" args "iron_sheet13"		"iron_sheet13"			0.9)
			("cut_part" args "iron_sheet14"		"iron_sheet14"			0.9)
			("cut_part" args "iron_sheet15"		"iron_sheet15"			0.9)
			("cut_part" args "iron_sheet16"		"iron_sheet16"			0.9)
			("cut_part" args "iron_sheet17"		"iron_sheet17"			0.9)
			("cut_part" args "iron_sheet18"		"iron_sheet18"			0.9)
			("cut_part" args "iron_sheet19"		"iron_sheet19"			0.9)
			("cut_part" args "iron_sheet20"		"iron_sheet20"			0.9)
			("cut_part" args "iron_sheet21"		"iron_sheet21"			0.9)
			("cut_part" args "iron_sheet21"		"iron_sheet21a"			0.9)
			("cut_part" args "iron_sheet22"		"iron_sheet22"			0.9)
			("cut_part" args "iron_sheet22"		"iron_sheet22a"			0.9)
			("cut_part" args "iron_sheet23"		"iron_sheet23"			0.9)
			("cut_part" args "iron_sheet24"		"iron_sheet24"			0.9)
			("cut_part" args "iron_sheet25"		"iron_sheet25"			0.9)
			("cut_part" args "iron_sheet26"		"iron_sheet26"			0.9)
			("cut_part" args "iron_sheet27"		"iron_sheet27"			0.9)
			("cut_part" args "iron_sheet28"		"iron_sheet28"			0.9)
			("cut_part" args "iron_sheet29"		"iron_sheet29"			0.9)
			("cut_part" args "iron_sheet30"		"iron_sheet30"			0.9)
			("cut_part" args "iron_sheet31"		"iron_sheet31"			0.9)
			("cut_part" args "wood00"		"wood00"			0.9)
			("cut_part" args "wood01"		"wood01"			0.9)
			("cut_part" args "wood02"		"wood02"			0.9)
			("cut_part" args "wood03"		"wood03"			0.9)
			("cut_part" args "wood04"		"wood04"			0.9)
			("cut_part" args "wood05"		"wood05"			0.9)
			("cut_part" args "wood06"		"wood06"			0.9)
			("cut_part" args "wood07"		"wood07"			0.9)
			("cut_part" args "wood08"		"wood08"			0.9)
			("cut_part" args "wood09"		"wood09"			0.9)
			("cut_part" args "wood10"		"wood10"			0.9)
			("cut_part" args "wood11"		"wood11"			0.9)
			("cut_part" args "wood12"		"wood12"			0.9)
			("cut_part" args "wood13"		"wood13"			0.9)
			("cut_part" args "wood14"		"wood14"			0.9)
			("cut_part" args "wood15"		"wood15"			0.9)
			("cut_part" args "wood16"		"wood16"			0.9)
			("cut_part" args "wood17"		"wood17"			0.9)
			("cut_part" args "wood18"		"wood18"			0.9)
			("cut_part" args "wood19"		"wood19"			0.9)
		else stuff "fx_40"
			{bullet_detonate}
			(define "cut_part"
				{if rand %2
					{if volume %1
						{spawn "metal_crush" %0}
						{delay 0.1
							{tear "piece_medium_steel_crushed" bone %0
								{impulse up 3 0.5 dir 1 0.5}
							}
						}
					else volume "frame"
						{set "end_stage" 1}
						{call "end_stage"}		
					}
				}
			)	
			("cut_part" args "plank00"		"plank00"			0.9)
			("cut_part" args "plank01"		"plank01"			0.9)
			("cut_part" args "plank02"		"plank02"			0.9)
			("cut_part" args "plank03"		"plank03"			0.9)
			("cut_part" args "plank04"		"plank04"			0.9)
			("cut_part" args "plank05"		"plank05"			0.9)
			("cut_part" args "plank06"		"plank06"			0.9)
			("cut_part" args "plank07"		"plank07"			0.9)
			("cut_part" args "plank08"		"plank08"			0.9)
			("cut_part" args "plank09"		"plank09"			0.9)
			("cut_part" args "plank10"		"plank10"			0.9)
			("cut_part" args "plank11"		"plank11"			0.9)
			("cut_part" args "plank12"		"plank12"			0.9)
			("cut_part" args "plank13"		"plank13"			0.9)
			("cut_part" args "steel00"		"steel00"			0.9)
			("cut_part" args "steel01"		"steel01"			0.9)
			("cut_part" args "steel02"		"steel02"			0.9)
			("cut_part" args "steel03"		"steel03"			0.9)
			("cut_part" args "steel04"		"steel04"			0.9)
			("cut_part" args "steel05"		"steel05"			0.9)
			("cut_part" args "steel06"		"steel06"			0.9)
			("cut_part" args "steel07"		"steel07"			0.9)
			("cut_part" args "steel08"		"steel08"			0.9)
			("cut_part" args "steel09"		"steel09"			0.9)
			("cut_part" args "steel10"		"steel10"			0.9)
			("cut_part" args "steel11"		"steel11"			0.9)
			("cut_part" args "steel12"		"steel12"			0.9)
			("cut_part" args "steel13"		"steel13"			0.9)
			("cut_part" args "steel14"		"steel14"			0.9)
			("cut_part" args "steel15"		"steel15"			0.9)
			("cut_part" args "steel16"		"steel16"			0.9)
			("cut_part" args "steel17"		"steel17"			0.9)
			("cut_part" args "steel18"		"steel18"			0.9)
			("cut_part" args "steel19"		"steel19"			0.9)
			("cut_part" args "steel20"		"steel20"			0.9)
			("cut_part" args "steel21"		"steel21"			0.9)
			("cut_part" args "steel22"		"steel22"			0.9)
			("cut_part" args "steel23"		"steel23"			0.9)
			("cut_part" args "steel24"		"steel24"			0.9)
			("cut_part" args "steel25"		"steel25"			0.9)
			("cut_part" args "steel26"		"steel26"			0.9)
			("cut_part" args "steel27"		"steel27"			0.9)
			("cut_part" args "steel28"		"steel28"			0.9)
			("cut_part" args "steel29"		"steel29"			0.9)
			("cut_part" args "steel30"		"steel30"			0.9)
			("cut_part" args "steel31"		"steel31"			0.9)
			("cut_part" args "steel32"		"steel32"			0.9)
			("cut_part" args "steel33"		"steel33"			0.9)
			("cut_part" args "iron_sheet00"		"iron_sheet00"			0.9)
			("cut_part" args "iron_sheet01"		"iron_sheet01"			0.9)
			("cut_part" args "iron_sheet02"		"iron_sheet02"			0.9)
			("cut_part" args "iron_sheet03"		"iron_sheet03"			0.9)
			("cut_part" args "iron_sheet04"		"iron_sheet04"			0.9)
			("cut_part" args "iron_sheet05"		"iron_sheet05"			0.9)
			("cut_part" args "iron_sheet06"		"iron_sheet06"			0.9)
			("cut_part" args "iron_sheet07"		"iron_sheet07"			0.9)
			("cut_part" args "iron_sheet08"		"iron_sheet08"			0.9)
			("cut_part" args "iron_sheet09"		"iron_sheet09"			0.9)
			("cut_part" args "iron_sheet10"		"iron_sheet10"			0.9)
			("cut_part" args "iron_sheet11"		"iron_sheet11"			0.9)
			("cut_part" args "iron_sheet12"		"iron_sheet12"			0.9)
			("cut_part" args "iron_sheet13"		"iron_sheet13"			0.9)
			("cut_part" args "iron_sheet14"		"iron_sheet14"			0.9)
			("cut_part" args "iron_sheet15"		"iron_sheet15"			0.9)
			("cut_part" args "iron_sheet16"		"iron_sheet16"			0.9)
			("cut_part" args "iron_sheet17"		"iron_sheet17"			0.9)
			("cut_part" args "iron_sheet18"		"iron_sheet18"			0.9)
			("cut_part" args "iron_sheet19"		"iron_sheet19"			0.9)
			("cut_part" args "iron_sheet20"		"iron_sheet20"			0.9)
			("cut_part" args "iron_sheet21"		"iron_sheet21"			0.9)
			("cut_part" args "iron_sheet21"		"iron_sheet21a"			0.9)
			("cut_part" args "iron_sheet22"		"iron_sheet22"			0.9)
			("cut_part" args "iron_sheet22"		"iron_sheet22a"			0.9)
			("cut_part" args "iron_sheet23"		"iron_sheet23"			0.9)
			("cut_part" args "iron_sheet24"		"iron_sheet24"			0.9)
			("cut_part" args "iron_sheet25"		"iron_sheet25"			0.9)
			("cut_part" args "iron_sheet26"		"iron_sheet26"			0.9)
			("cut_part" args "iron_sheet27"		"iron_sheet27"			0.9)
			("cut_part" args "iron_sheet28"		"iron_sheet28"			0.9)
			("cut_part" args "iron_sheet29"		"iron_sheet29"			0.9)
			("cut_part" args "iron_sheet30"		"iron_sheet30"			0.9)
			("cut_part" args "iron_sheet31"		"iron_sheet31"			0.9)
			("cut_part" args "wood00"		"wood00"			0.9)
			("cut_part" args "wood01"		"wood01"			0.9)
			("cut_part" args "wood02"		"wood02"			0.9)
			("cut_part" args "wood03"		"wood03"			0.9)
			("cut_part" args "wood04"		"wood04"			0.9)
			("cut_part" args "wood05"		"wood05"			0.9)
			("cut_part" args "wood06"		"wood06"			0.9)
			("cut_part" args "wood07"		"wood07"			0.9)
			("cut_part" args "wood08"		"wood08"			0.9)
			("cut_part" args "wood09"		"wood09"			0.9)
			("cut_part" args "wood10"		"wood10"			0.9)
			("cut_part" args "wood11"		"wood11"			0.9)
			("cut_part" args "wood12"		"wood12"			0.9)
			("cut_part" args "wood13"		"wood13"			0.9)
			("cut_part" args "wood14"		"wood14"			0.9)
			("cut_part" args "wood15"		"wood15"			0.9)
			("cut_part" args "wood16"		"wood16"			0.9)
			("cut_part" args "wood17"		"wood17"			0.9)
			("cut_part" args "wood18"		"wood18"			0.9)
			("cut_part" args "wood19"		"wood19"			0.9)
		else stuff "bullet"
			(define "cut_part_anim"
				{if volume %0
					{if not tagged "hit_plank_b_%3"
						{if not tagged "hit_plank_m_%3"
							{if rand %5
								{if not tagged "hit_plank_s_%3" 
									{ani_play "hit_plank_s_%3" 1}
								}
								{delay 0.1
									{tags add "hit_plank_s_%3"}
								}
								{if rand %4
									{if tagged "hit_plank_s_%3" 
										{tags add "hit_plank_m_%3"}
										{delay 0.01
											{ani_play "hit_plank_m_%3" 1}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_plank_m_%3" 
						{if rand %4
							{if not tagged "hit_plank_b_%3" 
								{delay 0.01
									{ani_play "hit_plank_b_%3" 1}
								}
							}
							{delay 0.01
								{tags add "hit_plank_b_%3"}
							}
						}
					}
					{if tagged "hit_plank_b_%3" 
						{if rand %4
							{if not tagged "hit_plank_bs_%3" 
								{delay 0.01
									{ani_play "hit_plank_bs_%3" 1}
								}
							}
							{delay 0.01
								{tags add "hit_plank_bs_%3"}
							}
						}
					}
					{if tagged "hit_plank_bs_%3" 
						{if rand %4
							{if not tagged "hit_plank_bm_%3" 
								{delay 0.01
									{ani_play "hit_plank_bm_%3" 1}
								}
							}
							{delay 0.01
								{tags add "hit_plank_bm_%3"}
							}
						}
					}
				}
				{if volume "tear"
					{if rand 0.1
						{tear "piece_medium_steel_crushed" bone from_volume
							{spawn "spheredust_small_short_arm" %0}
							{impulse up 1 0.5 dir 1 0.5}
						}	
					}	
				}	
				{if rand %2
					{if volume %1
						{delay 0
							{tear "piece_medium_steel_crushed" bone %0
								{spawn "metal_crush" %0}
								{impulse up 1 0.5 dir 1 0.5}
							}
						}
					else volume "frame"
						{set "end_stage" 1}
						{call "end_stage"}		
					}
				}
			)	
			;("cut_part_anim" args "frame"		"frame"				0.05	frame  	 0.1  0.3 )
			("cut_part_anim" args "plank00"		"plank00"			0.001	plank00  0.5  0.8 )
			("cut_part_anim" args "plank01"		"plank01"			0.001	plank01  0.5  0.8 )
			("cut_part_anim" args "plank02"		"plank02"			0.001	plank02  0.5  0.8 )
			("cut_part_anim" args "plank03"		"plank03"			0.001	plank03  0.5  0.8 )
			("cut_part_anim" args "plank04"		"plank04"			0.001	plank04  0.5  0.8 )
			("cut_part_anim" args "plank05"		"plank05"			0.001	plank05  0.5  0.8 )
			("cut_part_anim" args "plank06"		"plank06"			0.001	plank06  0.5  0.8 )
			("cut_part_anim" args "plank07"		"plank07"			0.001	plank07  0.5  0.8 )
			("cut_part_anim" args "plank08"		"plank08"			0.001	plank08  0.5  0.8 )
			("cut_part_anim" args "plank09"		"plank09"			0.001	plank09  0.5  0.8 )
			("cut_part_anim" args "plank10"		"plank10"			0.001	plank10  0.5  0.8 )
			("cut_part_anim" args "plank11"		"plank11"			0.001	plank11  0.5  0.8 )
			("cut_part_anim" args "plank12"		"plank12"			0.001	plank12  0.5  0.8 )
			("cut_part_anim" args "plank13"		"plank13"			0.001	plank13  0.5  0.8 )
			("cut_part_anim" args "steel00"		"steel00"			0.002		steel00  0.5  0.8 )
			("cut_part_anim" args "steel01"		"steel01"			0.002		steel01  0.5  0.8 )
			("cut_part_anim" args "steel02"		"steel02"			0.002		steel02  0.5  0.8 )
			("cut_part_anim" args "steel03"		"steel03"			0.002		steel03  0.5  0.8 )
			("cut_part_anim" args "steel04"		"steel04"			0.002		steel04  0.5  0.8 )
			("cut_part_anim" args "steel05"		"steel05"			0.002		steel05  0.5  0.8 )
			("cut_part_anim" args "steel06"		"steel06"			0.002		steel06  0.5  0.8 )
			("cut_part_anim" args "steel07"		"steel07"			0.002		steel07  0.5  0.8 )
			("cut_part_anim" args "steel08"		"steel08"			0.002		steel08  0.5  0.8 )
			("cut_part_anim" args "steel09"		"steel09"			0.002		steel09  0.5  0.8 )
			("cut_part_anim" args "steel10"		"steel10"			0.002		steel10  0.5  0.8 )
			("cut_part_anim" args "steel11"		"steel11"			0.002		steel11  0.5  0.8 )
			("cut_part_anim" args "steel12"		"steel12"			0.002		steel12  0.5  0.8 )
			("cut_part_anim" args "steel13"		"steel13"			0.002		steel13  0.5  0.8 )
			("cut_part_anim" args "steel14"		"steel14"			0.002		steel14  0.5  0.8 )
			("cut_part_anim" args "steel15"		"steel15"			0.002		steel15  0.5  0.8 )
			("cut_part_anim" args "steel16"		"steel16"			0.002		steel16  0.5  0.8 )
			("cut_part_anim" args "steel17"		"steel17"			0.002		steel17  0.5  0.8 )
			("cut_part_anim" args "steel18"		"steel18"			0.002		steel18  0.5  0.8 )
			("cut_part_anim" args "steel19"		"steel19"			0.002		steel19  0.5  0.8 )
			("cut_part_anim" args "steel20"		"steel20"			0.002		steel20  0.5  0.8 )
			("cut_part_anim" args "steel21"		"steel21"			0.002		steel21  0.5  0.8 )
			("cut_part_anim" args "steel22"		"steel22"			0.002		steel22  0.5  0.8 )
			("cut_part_anim" args "steel23"		"steel23"			0.002		steel23  0.5  0.8 )
			("cut_part_anim" args "steel24"		"steel24"			0.002		steel24  0.5  0.8 )
			("cut_part_anim" args "steel25"		"steel25"			0.002		steel25  0.5  0.8 )
			("cut_part_anim" args "steel26"		"steel26"			0.002		steel26  0.5  0.8 )
			("cut_part_anim" args "steel27"		"steel27"			0.002		steel27  0.5  0.8 )
			("cut_part_anim" args "steel28"		"steel28"			0.002		steel28  0.5  0.8 )
			("cut_part_anim" args "steel29"		"steel29"			0.002		steel29  0.5  0.8 )
			("cut_part_anim" args "steel30"		"steel30"			0.002		steel30  0.5  0.8 )
			("cut_part_anim" args "steel31"		"steel31"			0.002		steel31  0.5  0.8 )
			("cut_part_anim" args "steel32"		"steel32"			0.002		steel32  0.5  0.8 )
			("cut_part_anim" args "steel33"		"steel33"			0.002		steel33  0.5  0.8 )
			("cut_part_anim" args "iron_sheet00"		"iron_sheet00"			0.03		iron_sheet00  0.5  0.8 )
			("cut_part_anim" args "iron_sheet01"		"iron_sheet01"			0.03		iron_sheet01  0.5  0.8 )
			("cut_part_anim" args "iron_sheet02"		"iron_sheet02"			0.03		iron_sheet02  0.5  0.8 )
			("cut_part_anim" args "iron_sheet03"		"iron_sheet03"			0.03		iron_sheet03  0.5  0.8 )
			("cut_part_anim" args "iron_sheet04"		"iron_sheet04"			0.03		iron_sheet04  0.5  0.8 )
			("cut_part_anim" args "iron_sheet05"		"iron_sheet05"			0.03		iron_sheet05  0.5  0.8 )
			("cut_part_anim" args "iron_sheet06"		"iron_sheet06"			0.03		iron_sheet06  0.5  0.8 )
			("cut_part_anim" args "iron_sheet07"		"iron_sheet07"			0.03		iron_sheet07  0.5  0.8 )
			("cut_part_anim" args "iron_sheet08"		"iron_sheet08"			0.03		iron_sheet08  0.5  0.8 )
			("cut_part_anim" args "iron_sheet09"		"iron_sheet09"			0.03		iron_sheet09  0.5  0.8 )
			("cut_part_anim" args "iron_sheet10"		"iron_sheet10"			0.03		iron_sheet10  0.5  0.8 )
			("cut_part_anim" args "iron_sheet11"		"iron_sheet11"			0.03		iron_sheet11  0.5  0.8 )
			("cut_part_anim" args "iron_sheet12"		"iron_sheet12"			0.03		iron_sheet12  0.5  0.8 )
			("cut_part_anim" args "iron_sheet13"		"iron_sheet13"			0.03		iron_sheet13  0.5  0.8 )
			("cut_part_anim" args "iron_sheet14"		"iron_sheet14"			0.03		iron_sheet14  0.5  0.8 )
			("cut_part_anim" args "iron_sheet15"		"iron_sheet15"			0.03		iron_sheet15  0.5  0.8 )
			("cut_part_anim" args "iron_sheet16"		"iron_sheet16"			0.03		iron_sheet16  0.5  0.8 )
			("cut_part_anim" args "iron_sheet17"		"iron_sheet17"			0.03		iron_sheet17  0.5  0.8 )
			("cut_part_anim" args "iron_sheet18"		"iron_sheet18"			0.03		iron_sheet18  0.5  0.8 )
			("cut_part_anim" args "iron_sheet19"		"iron_sheet19"			0.03		iron_sheet19  0.5  0.8 )
			("cut_part_anim" args "iron_sheet20"		"iron_sheet20"			0.03		iron_sheet20  0.5  0.8 )
			("cut_part_anim" args "iron_sheet21"		"iron_sheet21"			0.03		iron_sheet21  0.5  0.8 )
			("cut_part_anim" args "iron_sheet21"		"iron_sheet21a"			0.03		iron_sheet21a  0.5  0.8 )
			("cut_part_anim" args "iron_sheet22"		"iron_sheet22"			0.03		iron_sheet22  0.5  0.8 )
			("cut_part_anim" args "iron_sheet22"		"iron_sheet22a"			0.03		iron_sheet22a  0.5  0.8 )
			("cut_part_anim" args "iron_sheet23"		"iron_sheet23"			0.03		iron_sheet23  0.5  0.8 )
			("cut_part_anim" args "iron_sheet24"		"iron_sheet24"			0.03		iron_sheet24  0.5  0.8 )
			("cut_part_anim" args "iron_sheet25"		"iron_sheet25"			0.03		iron_sheet25  0.5  0.8 )
			("cut_part_anim" args "iron_sheet26"		"iron_sheet26"			0.03		iron_sheet26  0.5  0.8 )
			("cut_part_anim" args "iron_sheet27"		"iron_sheet27"			0.03		iron_sheet27  0.5  0.8 )
			("cut_part_anim" args "iron_sheet28"		"iron_sheet28"			0.03		iron_sheet28  0.5  0.8 )
			("cut_part_anim" args "iron_sheet29"		"iron_sheet29"			0.03		iron_sheet29  0.5  0.8 )
			("cut_part_anim" args "iron_sheet30"		"iron_sheet30"			0.03		iron_sheet30  0.5  0.8 )
			("cut_part_anim" args "iron_sheet31"		"iron_sheet31"			0.03		iron_sheet31  0.5  0.8 )
			("cut_part_anim" args "wood00"		"wood00"			0.2		wood00  0.5  0.8 )
			("cut_part_anim" args "wood01"		"wood01"			0.2		wood01  0.5  0.8 )
			("cut_part_anim" args "wood02"		"wood02"			0.2		wood02  0.5  0.8 )
			("cut_part_anim" args "wood03"		"wood03"			0.2		wood03  0.5  0.8 )
			("cut_part_anim" args "wood04"		"wood04"			0.2		wood04  0.5  0.8 )
			("cut_part_anim" args "wood05"		"wood05"			0.2		wood05  0.5  0.8 )
			("cut_part_anim" args "wood06"		"wood06"			0.2		wood06  0.5  0.8 )
			("cut_part_anim" args "wood07"		"wood07"			0.2		wood07  0.5  0.8 )
			("cut_part_anim" args "wood08"		"wood08"			0.2		wood08  0.5  0.8 )
			("cut_part_anim" args "wood09"		"wood09"			0.2		wood09  0.5  0.8 )
			("cut_part_anim" args "wood10"		"wood10"			0.2		wood10  0.5  0.8 )
			("cut_part_anim" args "wood11"		"wood11"			0.2		wood11  0.5  0.8 )
			("cut_part_anim" args "wood12"		"wood12"			0.2		wood12  0.5  0.8 )
			("cut_part_anim" args "wood13"		"wood13"			0.2		wood13  0.5  0.8 )
			("cut_part_anim" args "wood14"		"wood14"			0.2		wood14  0.5  0.8 )
			("cut_part_anim" args "wood15"		"wood15"			0.2		wood15  0.5  0.8 )
			("cut_part_anim" args "wood16"		"wood16"			0.2		wood16  0.5  0.8 )
			("cut_part_anim" args "wood17"		"wood17"			0.2		wood17  0.5  0.8 )
			("cut_part_anim" args "wood18"		"wood18"			0.2		wood18  0.5  0.8 )
			("cut_part_anim" args "wood19"		"wood19"			0.2		wood19  0.5  0.8 )
		}
	}
	{on ground_hit
		{if contact_velocity 15
			{if volume "tear"
				{if rand 0.7
					{tear "piece_medium_steel_crushed" bone from_volume
						{spawn "spheredust_small_short_arm" }
						{impulse up 0.5 }
					}	
				}	
			}	
		}	
	}	
	{on contact 
		{if effector "fraction" 
			{if contact_velocity 1
				(define "cut_part"
					{if rand %2
						{if volume %1
							{tear "piece_medium_steel_crushed" bone %0
								{impulse up 2 1 dir 2 1}
							}
						}
					}
				)	
				("cut_part" args "plank00"		"plank00"				0.02)
				("cut_part" args "plank01"		"plank01"				0.02)
				("cut_part" args "plank02"		"plank02"				0.02)
				("cut_part" args "plank03"		"plank03"				0.02)
				("cut_part" args "plank04"		"plank04"				0.02)
				("cut_part" args "plank05"		"plank05"				0.02)
				("cut_part" args "plank06"		"plank06"				0.02)
				("cut_part" args "plank07"		"plank07"				0.02)
				("cut_part" args "plank08"		"plank08"				0.02)
				("cut_part" args "plank09"		"plank09"				0.02)
				("cut_part" args "plank10"		"plank10"				0.02)
				("cut_part" args "plank11"		"plank11"				0.02)
				("cut_part" args "plank12"		"plank12"				0.02)
				("cut_part" args "plank13"		"plank13"				0.02)
				("cut_part" args "steel00"		"steel00"				0.04)
				("cut_part" args "steel01"		"steel01"				0.04)
				("cut_part" args "steel02"		"steel02"				0.04)
				("cut_part" args "steel03"		"steel03"				0.04)
				("cut_part" args "steel04"		"steel04"				0.04)
				("cut_part" args "steel05"		"steel05"				0.04)
				("cut_part" args "steel06"		"steel06"				0.04)
				("cut_part" args "steel07"		"steel07"				0.04)
				("cut_part" args "steel08"		"steel08"				0.04)
				("cut_part" args "steel09"		"steel09"				0.04)
				("cut_part" args "steel10"		"steel10"				0.04)
				("cut_part" args "steel11"		"steel11"				0.04)
				("cut_part" args "steel12"		"steel12"				0.04)
				("cut_part" args "steel13"		"steel13"				0.04)
				("cut_part" args "steel14"		"steel14"				0.04)
				("cut_part" args "steel15"		"steel15"				0.04)
				("cut_part" args "steel16"		"steel16"				0.04)
				("cut_part" args "steel17"		"steel17"				0.04)
				("cut_part" args "steel18"		"steel18"				0.04)
				("cut_part" args "steel19"		"steel19"				0.04)
				("cut_part" args "steel20"		"steel20"				0.04)
				("cut_part" args "steel21"		"steel21"				0.04)
				("cut_part" args "steel22"		"steel22"				0.04)
				("cut_part" args "steel23"		"steel23"				0.04)
				("cut_part" args "steel24"		"steel24"				0.04)
				("cut_part" args "steel25"		"steel25"				0.04)
				("cut_part" args "steel26"		"steel26"				0.04)
				("cut_part" args "steel27"		"steel27"				0.04)
				("cut_part" args "steel28"		"steel28"				0.04)
				("cut_part" args "steel29"		"steel29"				0.04)
				("cut_part" args "steel30"		"steel30"				0.04)
				("cut_part" args "steel31"		"steel31"				0.04)
				("cut_part" args "steel32"		"steel32"				0.04)
				("cut_part" args "steel33"		"steel33"				0.04)
				("cut_part" args "iron_sheet00"		"iron_sheet00"				0.04)
				("cut_part" args "iron_sheet01"		"iron_sheet01"				0.04)
				("cut_part" args "iron_sheet02"		"iron_sheet02"				0.04)
				("cut_part" args "iron_sheet03"		"iron_sheet03"				0.04)
				("cut_part" args "iron_sheet04"		"iron_sheet04"				0.04)
				("cut_part" args "iron_sheet05"		"iron_sheet05"				0.04)
				("cut_part" args "iron_sheet06"		"iron_sheet06"				0.04)
				("cut_part" args "iron_sheet07"		"iron_sheet07"				0.04)
				("cut_part" args "iron_sheet08"		"iron_sheet08"				0.04)
				("cut_part" args "iron_sheet09"		"iron_sheet09"				0.04)
				("cut_part" args "iron_sheet10"		"iron_sheet10"				0.04)
				("cut_part" args "iron_sheet11"		"iron_sheet11"				0.04)
				("cut_part" args "iron_sheet12"		"iron_sheet12"				0.04)
				("cut_part" args "iron_sheet13"		"iron_sheet13"				0.04)
				("cut_part" args "iron_sheet14"		"iron_sheet14"				0.04)
				("cut_part" args "iron_sheet15"		"iron_sheet15"				0.04)
				("cut_part" args "iron_sheet16"		"iron_sheet16"				0.04)
				("cut_part" args "iron_sheet17"		"iron_sheet17"				0.04)
				("cut_part" args "iron_sheet18"		"iron_sheet18"				0.04)
				("cut_part" args "iron_sheet19"		"iron_sheet19"				0.04)
				("cut_part" args "iron_sheet20"		"iron_sheet20"				0.04)
				("cut_part" args "iron_sheet21"		"iron_sheet21"				0.04)
				("cut_part" args "iron_sheet21"		"iron_sheet21a"				0.04)
				("cut_part" args "iron_sheet22"		"iron_sheet22"				0.04)
				("cut_part" args "iron_sheet22"		"iron_sheet22a"				0.04)
				("cut_part" args "iron_sheet23"		"iron_sheet23"				0.04)
				("cut_part" args "iron_sheet24"		"iron_sheet24"				0.04)
				("cut_part" args "iron_sheet25"		"iron_sheet25"				0.04)
				("cut_part" args "iron_sheet26"		"iron_sheet26"				0.04)
				("cut_part" args "iron_sheet27"		"iron_sheet27"				0.04)
				("cut_part" args "iron_sheet28"		"iron_sheet28"			0.04)
				("cut_part" args "iron_sheet29"		"iron_sheet29"			0.04)
				("cut_part" args "iron_sheet30"		"iron_sheet30"			0.04)
				("cut_part" args "iron_sheet31"		"iron_sheet31"			0.04)
				("cut_part" args "wood00"		"wood00"				0.07)
				("cut_part" args "wood01"		"wood01"				0.07)
				("cut_part" args "wood02"		"wood02"				0.07)
				("cut_part" args "wood03"		"wood03"				0.07)
				("cut_part" args "wood04"		"wood04"				0.07)
				("cut_part" args "wood05"		"wood05"				0.07)
				("cut_part" args "wood06"		"wood06"				0.07)
				("cut_part" args "wood07"		"wood07"				0.07)
				("cut_part" args "wood08"		"wood08"				0.07)
				("cut_part" args "wood09"		"wood09"				0.07)
				("cut_part" args "wood10"		"wood10"				0.07)
				("cut_part" args "wood11"		"wood11"				0.07)
				("cut_part" args "wood12"		"wood12"				0.07)
				("cut_part" args "wood13"		"wood13"				0.07)
				("cut_part" args "wood14"		"wood14"				0.07)
				("cut_part" args "wood15"		"wood15"				0.07)
				("cut_part" args "wood16"		"wood16"				0.07)
				("cut_part" args "wood17"		"wood17"				0.07)
				("cut_part" args "wood18"		"wood18"				0.07)
				("cut_part" args "wood19"		"wood19"				0.07)
			}	
		else effector "tank" 
				(define "cut_part"
					{if volume %1
						{tear "piece_medium_steel_crushed" bone %0
							(define "disable_contact_blast_0")
							{impulse up 5 1 dir 2 1}
						}
					}
				)	
				("cut_part" args "plank00"		"plank00"				)
				("cut_part" args "plank01"		"plank01"				)
				("cut_part" args "plank02"		"plank02"				)
				("cut_part" args "plank03"		"plank03"				)
				("cut_part" args "plank04"		"plank04"				)
				("cut_part" args "plank05"		"plank05"				)
				("cut_part" args "plank06"		"plank06"				)
				("cut_part" args "plank07"		"plank07"				)
				("cut_part" args "plank08"		"plank08"				)
				("cut_part" args "plank09"		"plank09"				)
				("cut_part" args "plank10"		"plank10"				)
				("cut_part" args "plank11"		"plank11"				)
				("cut_part" args "plank12"		"plank12"				)
				("cut_part" args "plank13"		"plank13"				)
				("cut_part" args "steel00"		"steel00"				)
				("cut_part" args "steel01"		"steel01"				)
				("cut_part" args "steel02"		"steel02"				)
				("cut_part" args "steel03"		"steel03"				)
				("cut_part" args "steel04"		"steel04"				)
				("cut_part" args "steel05"		"steel05"				)
				("cut_part" args "steel06"		"steel06"				)
				("cut_part" args "steel07"		"steel07"				)
				("cut_part" args "steel08"		"steel08"				)
				("cut_part" args "steel09"		"steel09"				)
				("cut_part" args "steel10"		"steel10"				)
				("cut_part" args "steel11"		"steel11"				)
				("cut_part" args "steel12"		"steel12"				)
				("cut_part" args "steel13"		"steel13"				)
				("cut_part" args "steel14"		"steel14"				)
				("cut_part" args "steel15"		"steel15"				)
				("cut_part" args "steel16"		"steel16"				)
				("cut_part" args "steel17"		"steel17"				)
				("cut_part" args "steel18"		"steel18"				)
				("cut_part" args "steel19"		"steel19"				)
				("cut_part" args "steel20"		"steel20"				)
				("cut_part" args "steel21"		"steel21"				)
				("cut_part" args "steel22"		"steel22"				)
				("cut_part" args "steel23"		"steel23"				)
				("cut_part" args "steel24"		"steel24"				)
				("cut_part" args "steel25"		"steel25"				)
				("cut_part" args "steel26"		"steel26"				)
				("cut_part" args "steel27"		"steel27"				)
				("cut_part" args "steel28"		"steel28"				)
				("cut_part" args "steel29"		"steel29"				)
				("cut_part" args "steel30"		"steel30"				)
				("cut_part" args "steel31"		"steel31"				)
				("cut_part" args "steel32"		"steel32"				)
				("cut_part" args "steel33"		"steel33"				)
				("cut_part" args "iron_sheet00"		"iron_sheet00"				)
				("cut_part" args "iron_sheet01"		"iron_sheet01"				)
				("cut_part" args "iron_sheet02"		"iron_sheet02"				)
				("cut_part" args "iron_sheet03"		"iron_sheet03"				)
				("cut_part" args "iron_sheet04"		"iron_sheet04"				)
				("cut_part" args "iron_sheet05"		"iron_sheet05"				)
				("cut_part" args "iron_sheet06"		"iron_sheet06"				)
				("cut_part" args "iron_sheet07"		"iron_sheet07"				)
				("cut_part" args "iron_sheet08"		"iron_sheet08"				)
				("cut_part" args "iron_sheet09"		"iron_sheet09"				)
				("cut_part" args "iron_sheet10"		"iron_sheet10"				)
				("cut_part" args "iron_sheet11"		"iron_sheet11"				)
				("cut_part" args "iron_sheet12"		"iron_sheet12"				)
				("cut_part" args "iron_sheet13"		"iron_sheet13"				)
				("cut_part" args "iron_sheet14"		"iron_sheet14"				)
				("cut_part" args "iron_sheet15"		"iron_sheet15"				)
				("cut_part" args "iron_sheet16"		"iron_sheet16"				)
				("cut_part" args "iron_sheet17"		"iron_sheet17"				)
				("cut_part" args "iron_sheet18"		"iron_sheet18"				)
				("cut_part" args "iron_sheet19"		"iron_sheet19"				)
				("cut_part" args "iron_sheet20"		"iron_sheet20"				)
				("cut_part" args "iron_sheet21"		"iron_sheet21"				)
				("cut_part" args "iron_sheet21"		"iron_sheet21a"				)
				("cut_part" args "iron_sheet22"		"iron_sheet22"				)
				("cut_part" args "iron_sheet22"		"iron_sheet22a"				)
				("cut_part" args "iron_sheet23"		"iron_sheet23"				)
				("cut_part" args "iron_sheet24"		"iron_sheet24"				)
				("cut_part" args "iron_sheet25"		"iron_sheet25"				)
				("cut_part" args "iron_sheet26"		"iron_sheet26"				)
				("cut_part" args "iron_sheet27"		"iron_sheet27"				)
				("cut_part" args "iron_sheet28"		"iron_sheet28"			)
				("cut_part" args "iron_sheet29"		"iron_sheet29"			)
				("cut_part" args "iron_sheet30"		"iron_sheet30"			)
				("cut_part" args "iron_sheet31"		"iron_sheet31"			)
				("cut_part" args "wood00"		"wood00"				)
				("cut_part" args "wood01"		"wood01"				)
				("cut_part" args "wood02"		"wood02"				)
				("cut_part" args "wood03"		"wood03"				)
				("cut_part" args "wood04"		"wood04"				)
				("cut_part" args "wood05"		"wood05"				)
				("cut_part" args "wood06"		"wood06"				)
				("cut_part" args "wood07"		"wood07"				)
				("cut_part" args "wood08"		"wood08"				)
				("cut_part" args "wood09"		"wood09"				)
				("cut_part" args "wood10"		"wood10"				)
				("cut_part" args "wood11"		"wood11"				)
				("cut_part" args "wood12"		"wood12"				)
				("cut_part" args "wood13"		"wood13"				)
				("cut_part" args "wood14"		"wood14"				)
				("cut_part" args "wood15"		"wood15"				)
				("cut_part" args "wood16"		"wood16"				)
				("cut_part" args "wood17"		"wood17"				)
				("cut_part" args "wood18"		"wood18"				)
				("cut_part" args "wood19"		"wood19"				)
		else effector "helicopter" 
				(define "cut_part"
					{if volume %1
						{tear "piece_medium_steel_crushed" bone %0
							{spawn "break_metal" %0}
							{impulse up 6 4 dir 18 1}
						}
					}
				)	
				("cut_part" args "plank00"		"plank00"				)
				("cut_part" args "plank01"		"plank01"				)
				("cut_part" args "plank02"		"plank02"				)
				("cut_part" args "plank03"		"plank03"				)
				("cut_part" args "plank04"		"plank04"				)
				("cut_part" args "plank05"		"plank05"				)
				("cut_part" args "plank06"		"plank06"				)
				("cut_part" args "plank07"		"plank07"				)
				("cut_part" args "plank08"		"plank08"				)
				("cut_part" args "plank09"		"plank09"				)
				("cut_part" args "plank10"		"plank10"				)
				("cut_part" args "plank11"		"plank11"				)
				("cut_part" args "plank12"		"plank12"				)
				("cut_part" args "plank13"		"plank13"				)
				("cut_part" args "steel00"		"steel00"				)
				("cut_part" args "steel01"		"steel01"				)
				("cut_part" args "steel02"		"steel02"				)
				("cut_part" args "steel03"		"steel03"				)
				("cut_part" args "steel04"		"steel04"				)
				("cut_part" args "steel05"		"steel05"				)
				("cut_part" args "steel06"		"steel06"				)
				("cut_part" args "steel07"		"steel07"				)
				("cut_part" args "steel08"		"steel08"				)
				("cut_part" args "steel09"		"steel09"				)
				("cut_part" args "steel10"		"steel10"				)
				("cut_part" args "steel11"		"steel11"				)
				("cut_part" args "steel12"		"steel12"				)
				("cut_part" args "steel13"		"steel13"				)
				("cut_part" args "steel14"		"steel14"				)
				("cut_part" args "steel15"		"steel15"				)
				("cut_part" args "steel16"		"steel16"				)
				("cut_part" args "steel17"		"steel17"				)
				("cut_part" args "steel18"		"steel18"				)
				("cut_part" args "steel19"		"steel19"				)
				("cut_part" args "steel20"		"steel20"				)
				("cut_part" args "steel21"		"steel21"				)
				("cut_part" args "steel22"		"steel22"				)
				("cut_part" args "steel23"		"steel23"				)
				("cut_part" args "steel24"		"steel24"				)
				("cut_part" args "steel25"		"steel25"				)
				("cut_part" args "steel26"		"steel26"				)
				("cut_part" args "steel27"		"steel27"				)
				("cut_part" args "steel28"		"steel28"				)
				("cut_part" args "steel29"		"steel29"				)
				("cut_part" args "steel30"		"steel30"				)
				("cut_part" args "steel31"		"steel31"				)
				("cut_part" args "steel32"		"steel32"				)
				("cut_part" args "steel33"		"steel33"				)
				("cut_part" args "iron_sheet00"		"iron_sheet00"				)
				("cut_part" args "iron_sheet01"		"iron_sheet01"				)
				("cut_part" args "iron_sheet02"		"iron_sheet02"				)
				("cut_part" args "iron_sheet03"		"iron_sheet03"				)
				("cut_part" args "iron_sheet04"		"iron_sheet04"				)
				("cut_part" args "iron_sheet05"		"iron_sheet05"				)
				("cut_part" args "iron_sheet06"		"iron_sheet06"				)
				("cut_part" args "iron_sheet07"		"iron_sheet07"				)
				("cut_part" args "iron_sheet08"		"iron_sheet08"				)
				("cut_part" args "iron_sheet09"		"iron_sheet09"				)
				("cut_part" args "iron_sheet10"		"iron_sheet10"				)
				("cut_part" args "iron_sheet11"		"iron_sheet11"				)
				("cut_part" args "iron_sheet12"		"iron_sheet12"				)
				("cut_part" args "iron_sheet13"		"iron_sheet13"				)
				("cut_part" args "iron_sheet14"		"iron_sheet14"				)
				("cut_part" args "iron_sheet15"		"iron_sheet15"				)
				("cut_part" args "iron_sheet16"		"iron_sheet16"				)
				("cut_part" args "iron_sheet17"		"iron_sheet17"				)
				("cut_part" args "iron_sheet18"		"iron_sheet18"				)
				("cut_part" args "iron_sheet19"		"iron_sheet19"				)
				("cut_part" args "iron_sheet20"		"iron_sheet20"				)
				("cut_part" args "iron_sheet21"		"iron_sheet21"				)
				("cut_part" args "iron_sheet21"		"iron_sheet21a"				)
				("cut_part" args "iron_sheet22"		"iron_sheet22"				)
				("cut_part" args "iron_sheet22"		"iron_sheet22a"				)
				("cut_part" args "iron_sheet23"		"iron_sheet23"				)
				("cut_part" args "iron_sheet24"		"iron_sheet24"				)
				("cut_part" args "iron_sheet25"		"iron_sheet25"				)
				("cut_part" args "iron_sheet26"		"iron_sheet26"				)
				("cut_part" args "iron_sheet27"		"iron_sheet27"				)
				("cut_part" args "iron_sheet28"		"iron_sheet28"			)
				("cut_part" args "iron_sheet29"		"iron_sheet29"			)
				("cut_part" args "iron_sheet30"		"iron_sheet30"			)
				("cut_part" args "iron_sheet31"		"iron_sheet31"			)
				("cut_part" args "wood00"		"wood00"				)
				("cut_part" args "wood01"		"wood01"				)
				("cut_part" args "wood02"		"wood02"				)
				("cut_part" args "wood03"		"wood03"				)
				("cut_part" args "wood04"		"wood04"				)
				("cut_part" args "wood05"		"wood05"				)
				("cut_part" args "wood06"		"wood06"				)
				("cut_part" args "wood07"		"wood07"				)
				("cut_part" args "wood08"		"wood08"				)
				("cut_part" args "wood09"		"wood09"				)
				("cut_part" args "wood10"		"wood10"				)
				("cut_part" args "wood11"		"wood11"				)
				("cut_part" args "wood12"		"wood12"				)
				("cut_part" args "wood13"		"wood13"				)
				("cut_part" args "wood14"		"wood14"				)
				("cut_part" args "wood15"		"wood15"				)
				("cut_part" args "wood16"		"wood16"				)
				("cut_part" args "wood17"		"wood17"				)
				("cut_part" args "wood18"		"wood18"				)
				("cut_part" args "wood19"		"wood19"				)
		else effector "vehicle" 
			{if contact_velocity 25
				(define "cut_part"
					{if volume %1
						{tear "piece_medium_steel_crushed" bone %0
							(define "disable_contact_blast_0")
							{impulse up 12 1 dir 6 1}
						}
					}
				)	
				("cut_part" args "plank00"		"plank00"				)
				("cut_part" args "plank01"		"plank01"				)
				("cut_part" args "plank02"		"plank02"				)
				("cut_part" args "plank03"		"plank03"				)
				("cut_part" args "plank04"		"plank04"				)
				("cut_part" args "plank05"		"plank05"				)
				("cut_part" args "plank06"		"plank06"				)
				("cut_part" args "plank07"		"plank07"				)
				("cut_part" args "plank08"		"plank08"				)
				("cut_part" args "plank09"		"plank09"				)
				("cut_part" args "plank10"		"plank10"				)
				("cut_part" args "plank11"		"plank11"				)
				("cut_part" args "plank12"		"plank12"				)
				("cut_part" args "plank13"		"plank13"				)
				("cut_part" args "steel00"		"steel00"				)
				("cut_part" args "steel01"		"steel01"				)
				("cut_part" args "steel02"		"steel02"				)
				("cut_part" args "steel03"		"steel03"				)
				("cut_part" args "steel04"		"steel04"				)
				("cut_part" args "steel05"		"steel05"				)
				("cut_part" args "steel06"		"steel06"				)
				("cut_part" args "steel07"		"steel07"				)
				("cut_part" args "steel08"		"steel08"				)
				("cut_part" args "steel09"		"steel09"				)
				("cut_part" args "steel10"		"steel10"				)
				("cut_part" args "steel11"		"steel11"				)
				("cut_part" args "steel12"		"steel12"				)
				("cut_part" args "steel13"		"steel13"				)
				("cut_part" args "steel14"		"steel14"				)
				("cut_part" args "steel15"		"steel15"				)
				("cut_part" args "steel16"		"steel16"				)
				("cut_part" args "steel17"		"steel17"				)
				("cut_part" args "steel18"		"steel18"				)
				("cut_part" args "steel19"		"steel19"				)
				("cut_part" args "steel20"		"steel20"				)
				("cut_part" args "steel21"		"steel21"				)
				("cut_part" args "steel22"		"steel22"				)
				("cut_part" args "steel23"		"steel23"				)
				("cut_part" args "steel24"		"steel24"				)
				("cut_part" args "steel25"		"steel25"				)
				("cut_part" args "steel26"		"steel26"				)
				("cut_part" args "steel27"		"steel27"				)
				("cut_part" args "steel28"		"steel28"				)
				("cut_part" args "steel29"		"steel29"				)
				("cut_part" args "steel30"		"steel30"				)
				("cut_part" args "steel31"		"steel31"				)
				("cut_part" args "steel32"		"steel32"				)
				("cut_part" args "steel33"		"steel33"				)
				("cut_part" args "iron_sheet00"		"iron_sheet00"				)
				("cut_part" args "iron_sheet01"		"iron_sheet01"				)
				("cut_part" args "iron_sheet02"		"iron_sheet02"				)
				("cut_part" args "iron_sheet03"		"iron_sheet03"				)
				("cut_part" args "iron_sheet04"		"iron_sheet04"				)
				("cut_part" args "iron_sheet05"		"iron_sheet05"				)
				("cut_part" args "iron_sheet06"		"iron_sheet06"				)
				("cut_part" args "iron_sheet07"		"iron_sheet07"				)
				("cut_part" args "iron_sheet08"		"iron_sheet08"				)
				("cut_part" args "iron_sheet09"		"iron_sheet09"				)
				("cut_part" args "iron_sheet10"		"iron_sheet10"				)
				("cut_part" args "iron_sheet11"		"iron_sheet11"				)
				("cut_part" args "iron_sheet12"		"iron_sheet12"				)
				("cut_part" args "iron_sheet13"		"iron_sheet13"				)
				("cut_part" args "iron_sheet14"		"iron_sheet14"				)
				("cut_part" args "iron_sheet15"		"iron_sheet15"				)
				("cut_part" args "iron_sheet16"		"iron_sheet16"				)
				("cut_part" args "iron_sheet17"		"iron_sheet17"				)
				("cut_part" args "iron_sheet18"		"iron_sheet18"				)
				("cut_part" args "iron_sheet19"		"iron_sheet19"				)
				("cut_part" args "iron_sheet20"		"iron_sheet20"				)
				("cut_part" args "iron_sheet21"		"iron_sheet21"				)
				("cut_part" args "iron_sheet21"		"iron_sheet21a"				)
				("cut_part" args "iron_sheet22"		"iron_sheet22"				)
				("cut_part" args "iron_sheet22"		"iron_sheet22a"				)
				("cut_part" args "iron_sheet23"		"iron_sheet23"				)
				("cut_part" args "iron_sheet24"		"iron_sheet24"				)
				("cut_part" args "iron_sheet25"		"iron_sheet25"				)
				("cut_part" args "iron_sheet26"		"iron_sheet26"				)
				("cut_part" args "iron_sheet27"		"iron_sheet27"				)
				("cut_part" args "iron_sheet28"		"iron_sheet28"			)
				("cut_part" args "iron_sheet29"		"iron_sheet29"			)
				("cut_part" args "iron_sheet30"		"iron_sheet30"			)
				("cut_part" args "iron_sheet31"		"iron_sheet31"			)
				("cut_part" args "wood00"		"wood00"				)
				("cut_part" args "wood01"		"wood01"				)
				("cut_part" args "wood02"		"wood02"				)
				("cut_part" args "wood03"		"wood03"				)
				("cut_part" args "wood04"		"wood04"				)
				("cut_part" args "wood05"		"wood05"				)
				("cut_part" args "wood06"		"wood06"				)
				("cut_part" args "wood07"		"wood07"				)
				("cut_part" args "wood08"		"wood08"				)
				("cut_part" args "wood09"		"wood09"				)
				("cut_part" args "wood10"		"wood10"				)
				("cut_part" args "wood11"		"wood11"				)
				("cut_part" args "wood12"		"wood12"				)
				("cut_part" args "wood13"		"wood13"				)
				("cut_part" args "wood14"		"wood14"				)
				("cut_part" args "wood15"		"wood15"				)
				("cut_part" args "wood16"		"wood16"				)
				("cut_part" args "wood17"		"wood17"				)
				("cut_part" args "wood18"		"wood18"				)
				("cut_part" args "wood19"		"wood19"				)
			else contact_velocity 15
				(define "cut_part"
					{if rand %2
						{if volume %1
							{tear "piece_medium_steel_crushed" bone %0
								(define "disable_contact_blast_0")
								{impulse up 2 1 dir 2 1}
							}
						}
					}
				)	
				("cut_part" args "plank00"		"plank00"				0.7)
				("cut_part" args "plank01"		"plank01"				0.7)
				("cut_part" args "plank02"		"plank02"				0.7)
				("cut_part" args "plank03"		"plank03"				0.7)
				("cut_part" args "plank04"		"plank04"				0.7)
				("cut_part" args "plank05"		"plank05"				0.7)
				("cut_part" args "plank06"		"plank06"				0.7)
				("cut_part" args "plank07"		"plank07"				0.7)
				("cut_part" args "plank08"		"plank08"				0.7)
				("cut_part" args "plank09"		"plank09"				0.7)
				("cut_part" args "plank10"		"plank10"				0.7)
				("cut_part" args "plank11"		"plank11"				0.7)
				("cut_part" args "plank12"		"plank12"				0.7)
				("cut_part" args "plank13"		"plank13"				0.7)
				("cut_part" args "steel00"		"steel00"				0.9)
				("cut_part" args "steel01"		"steel01"				0.9)
				("cut_part" args "steel02"		"steel02"				0.9)
				("cut_part" args "steel03"		"steel03"				0.9)
				("cut_part" args "steel04"		"steel04"				0.9)
				("cut_part" args "steel05"		"steel05"				0.9)
				("cut_part" args "steel06"		"steel06"				0.9)
				("cut_part" args "steel07"		"steel07"				0.9)
				("cut_part" args "steel08"		"steel08"				0.9)
				("cut_part" args "steel09"		"steel09"				0.9)
				("cut_part" args "steel10"		"steel10"				0.9)
				("cut_part" args "steel11"		"steel11"				0.9)
				("cut_part" args "steel12"		"steel12"				0.9)
				("cut_part" args "steel13"		"steel13"				0.9)
				("cut_part" args "steel14"		"steel14"				0.9)
				("cut_part" args "steel15"		"steel15"				0.9)
				("cut_part" args "steel16"		"steel16"				0.9)
				("cut_part" args "steel17"		"steel17"				0.9)
				("cut_part" args "steel18"		"steel18"				0.9)
				("cut_part" args "steel19"		"steel19"				0.9)
				("cut_part" args "steel20"		"steel20"				0.9)
				("cut_part" args "steel21"		"steel21"				0.9)
				("cut_part" args "steel22"		"steel22"				0.9)
				("cut_part" args "steel23"		"steel23"				0.9)
				("cut_part" args "steel24"		"steel24"				0.9)
				("cut_part" args "steel25"		"steel25"				0.9)
				("cut_part" args "steel26"		"steel26"				0.9)
				("cut_part" args "steel27"		"steel27"				0.9)
				("cut_part" args "steel28"		"steel28"				0.9)
				("cut_part" args "steel29"		"steel29"				0.9)
				("cut_part" args "steel30"		"steel30"				0.9)
				("cut_part" args "steel31"		"steel31"				0.9)
				("cut_part" args "steel32"		"steel32"				0.9)
				("cut_part" args "steel33"		"steel33"				0.9)
				("cut_part" args "iron_sheet00"		"iron_sheet00"				0.9)
				("cut_part" args "iron_sheet01"		"iron_sheet01"				0.9)
				("cut_part" args "iron_sheet02"		"iron_sheet02"				0.9)
				("cut_part" args "iron_sheet03"		"iron_sheet03"				0.9)
				("cut_part" args "iron_sheet04"		"iron_sheet04"				0.9)
				("cut_part" args "iron_sheet05"		"iron_sheet05"				0.9)
				("cut_part" args "iron_sheet06"		"iron_sheet06"				0.9)
				("cut_part" args "iron_sheet07"		"iron_sheet07"				0.9)
				("cut_part" args "iron_sheet08"		"iron_sheet08"				0.9)
				("cut_part" args "iron_sheet09"		"iron_sheet09"				0.9)
				("cut_part" args "iron_sheet10"		"iron_sheet10"				0.9)
				("cut_part" args "iron_sheet11"		"iron_sheet11"				0.9)
				("cut_part" args "iron_sheet12"		"iron_sheet12"				0.9)
				("cut_part" args "iron_sheet13"		"iron_sheet13"				0.9)
				("cut_part" args "iron_sheet14"		"iron_sheet14"				0.9)
				("cut_part" args "iron_sheet15"		"iron_sheet15"				0.9)
				("cut_part" args "iron_sheet16"		"iron_sheet16"				0.9)
				("cut_part" args "iron_sheet17"		"iron_sheet17"				0.9)
				("cut_part" args "iron_sheet18"		"iron_sheet18"				0.9)
				("cut_part" args "iron_sheet19"		"iron_sheet19"				0.9)
				("cut_part" args "iron_sheet20"		"iron_sheet20"				0.9)
				("cut_part" args "iron_sheet21"		"iron_sheet21"				0.9)
				("cut_part" args "iron_sheet21"		"iron_sheet21a"				0.9)
				("cut_part" args "iron_sheet22"		"iron_sheet22"				0.9)
				("cut_part" args "iron_sheet22"		"iron_sheet22a"				0.9)
				("cut_part" args "iron_sheet23"		"iron_sheet23"				0.9)
				("cut_part" args "iron_sheet24"		"iron_sheet24"				0.9)
				("cut_part" args "iron_sheet25"		"iron_sheet25"				0.9)
				("cut_part" args "iron_sheet26"		"iron_sheet26"				0.9)
				("cut_part" args "iron_sheet27"		"iron_sheet27"				0.9)
				("cut_part" args "iron_sheet28"		"iron_sheet28"			0.9)
				("cut_part" args "iron_sheet29"		"iron_sheet29"			0.9)
				("cut_part" args "iron_sheet30"		"iron_sheet30"			0.9)
				("cut_part" args "iron_sheet31"		"iron_sheet31"			0.9)
				("cut_part" args "wood00"		"wood00"				0.9)
				("cut_part" args "wood01"		"wood01"				0.9)
				("cut_part" args "wood02"		"wood02"				0.9)
				("cut_part" args "wood03"		"wood03"				0.9)
				("cut_part" args "wood04"		"wood04"				0.9)
				("cut_part" args "wood05"		"wood05"				0.9)
				("cut_part" args "wood06"		"wood06"				0.9)
				("cut_part" args "wood07"		"wood07"				0.9)
				("cut_part" args "wood08"		"wood08"				0.9)
				("cut_part" args "wood09"		"wood09"				0.9)
				("cut_part" args "wood10"		"wood10"				0.9)
				("cut_part" args "wood11"		"wood11"				0.9)
				("cut_part" args "wood12"		"wood12"				0.9)
				("cut_part" args "wood13"		"wood13"				0.9)
				("cut_part" args "wood14"		"wood14"				0.9)
				("cut_part" args "wood15"		"wood15"				0.9)
				("cut_part" args "wood16"		"wood16"				0.9)
				("cut_part" args "wood17"		"wood17"				0.9)
				("cut_part" args "wood18"		"wood18"				0.9)
				("cut_part" args "wood19"		"wood19"				0.9)
			else contact_velocity 5
				(define "cut_part"
					{if rand %2
						{if volume %1
							{tear "piece_medium_steel_crushed" bone %0
								(define "disable_contact_blast_0")
								{impulse up 2 1 dir 2 1}
							}
						}
					}
				)	
				("cut_part" args "plank00"		"plank00"				0.3)
				("cut_part" args "plank01"		"plank01"				0.3)
				("cut_part" args "plank02"		"plank02"				0.3)
				("cut_part" args "plank03"		"plank03"				0.3)
				("cut_part" args "plank04"		"plank04"				0.3)
				("cut_part" args "plank05"		"plank05"				0.3)
				("cut_part" args "plank06"		"plank06"				0.3)
				("cut_part" args "plank07"		"plank07"				0.3)
				("cut_part" args "plank08"		"plank08"				0.3)
				("cut_part" args "plank09"		"plank09"				0.3)
				("cut_part" args "plank10"		"plank10"				0.3)
				("cut_part" args "plank11"		"plank11"				0.3)
				("cut_part" args "plank12"		"plank12"				0.3)
				("cut_part" args "plank13"		"plank13"				0.3)
				("cut_part" args "steel00"		"steel00"				0.5)
				("cut_part" args "steel01"		"steel01"				0.5)
				("cut_part" args "steel02"		"steel02"				0.5)
				("cut_part" args "steel03"		"steel03"				0.5)
				("cut_part" args "steel04"		"steel04"				0.5)
				("cut_part" args "steel05"		"steel05"				0.5)
				("cut_part" args "steel06"		"steel06"				0.5)
				("cut_part" args "steel07"		"steel07"				0.5)
				("cut_part" args "steel08"		"steel08"				0.5)
				("cut_part" args "steel09"		"steel09"				0.5)
				("cut_part" args "steel10"		"steel10"				0.5)
				("cut_part" args "steel11"		"steel11"				0.5)
				("cut_part" args "steel12"		"steel12"				0.5)
				("cut_part" args "steel13"		"steel13"				0.5)
				("cut_part" args "steel14"		"steel14"				0.5)
				("cut_part" args "steel15"		"steel15"				0.5)
				("cut_part" args "steel16"		"steel16"				0.5)
				("cut_part" args "steel17"		"steel17"				0.5)
				("cut_part" args "steel18"		"steel18"				0.5)
				("cut_part" args "steel19"		"steel19"				0.5)
				("cut_part" args "steel20"		"steel20"				0.5)
				("cut_part" args "steel21"		"steel21"				0.5)
				("cut_part" args "steel22"		"steel22"				0.5)
				("cut_part" args "steel23"		"steel23"				0.5)
				("cut_part" args "steel24"		"steel24"				0.5)
				("cut_part" args "steel25"		"steel25"				0.5)
				("cut_part" args "steel26"		"steel26"				0.5)
				("cut_part" args "steel27"		"steel27"				0.5)
				("cut_part" args "steel28"		"steel28"				0.5)
				("cut_part" args "steel29"		"steel29"				0.5)
				("cut_part" args "steel30"		"steel30"				0.5)
				("cut_part" args "steel31"		"steel31"				0.5)
				("cut_part" args "steel32"		"steel32"				0.5)
				("cut_part" args "steel33"		"steel33"				0.5)
				("cut_part" args "iron_sheet00"		"iron_sheet00"				0.5)
				("cut_part" args "iron_sheet01"		"iron_sheet01"				0.5)
				("cut_part" args "iron_sheet02"		"iron_sheet02"				0.5)
				("cut_part" args "iron_sheet03"		"iron_sheet03"				0.5)
				("cut_part" args "iron_sheet04"		"iron_sheet04"				0.5)
				("cut_part" args "iron_sheet05"		"iron_sheet05"				0.5)
				("cut_part" args "iron_sheet06"		"iron_sheet06"				0.5)
				("cut_part" args "iron_sheet07"		"iron_sheet07"				0.5)
				("cut_part" args "iron_sheet08"		"iron_sheet08"				0.5)
				("cut_part" args "iron_sheet09"		"iron_sheet09"				0.5)
				("cut_part" args "iron_sheet10"		"iron_sheet10"				0.5)
				("cut_part" args "iron_sheet11"		"iron_sheet11"				0.5)
				("cut_part" args "iron_sheet12"		"iron_sheet12"				0.5)
				("cut_part" args "iron_sheet13"		"iron_sheet13"				0.5)
				("cut_part" args "iron_sheet14"		"iron_sheet14"				0.5)
				("cut_part" args "iron_sheet15"		"iron_sheet15"				0.5)
				("cut_part" args "iron_sheet16"		"iron_sheet16"				0.5)
				("cut_part" args "iron_sheet17"		"iron_sheet17"				0.5)
				("cut_part" args "iron_sheet18"		"iron_sheet18"				0.5)
				("cut_part" args "iron_sheet19"		"iron_sheet19"				0.5)
				("cut_part" args "iron_sheet20"		"iron_sheet20"				0.5)
				("cut_part" args "iron_sheet21"		"iron_sheet21"				0.5)
				("cut_part" args "iron_sheet21"		"iron_sheet21a"				0.5)
				("cut_part" args "iron_sheet22"		"iron_sheet22"				0.5)
				("cut_part" args "iron_sheet22"		"iron_sheet22a"				0.5)
				("cut_part" args "iron_sheet23"		"iron_sheet23"				0.5)
				("cut_part" args "iron_sheet24"		"iron_sheet24"				0.5)
				("cut_part" args "iron_sheet25"		"iron_sheet25"				0.5)
				("cut_part" args "iron_sheet26"		"iron_sheet26"				0.5)
				("cut_part" args "iron_sheet27"		"iron_sheet27"				0.5)
				("cut_part" args "iron_sheet28"		"iron_sheet28"			0.5)
				("cut_part" args "iron_sheet29"		"iron_sheet29"			0.5)
				("cut_part" args "iron_sheet30"		"iron_sheet30"			0.5)
				("cut_part" args "iron_sheet31"		"iron_sheet31"			0.5)
				("cut_part" args "wood00"		"wood00"				0.5)
				("cut_part" args "wood01"		"wood01"				0.5)
				("cut_part" args "wood02"		"wood02"				0.5)
				("cut_part" args "wood03"		"wood03"				0.5)
				("cut_part" args "wood04"		"wood04"				0.5)
				("cut_part" args "wood05"		"wood05"				0.5)
				("cut_part" args "wood06"		"wood06"				0.5)
				("cut_part" args "wood07"		"wood07"				0.5)
				("cut_part" args "wood08"		"wood08"				0.5)
				("cut_part" args "wood09"		"wood09"				0.5)
				("cut_part" args "wood10"		"wood10"				0.5)
				("cut_part" args "wood11"		"wood11"				0.5)
				("cut_part" args "wood12"		"wood12"				0.5)
				("cut_part" args "wood13"		"wood13"				0.5)
				("cut_part" args "wood14"		"wood14"				0.5)
				("cut_part" args "wood15"		"wood15"				0.5)
				("cut_part" args "wood16"		"wood16"				0.5)
				("cut_part" args "wood17"		"wood17"				0.5)
				("cut_part" args "wood18"		"wood18"				0.5)
				("cut_part" args "wood19"		"wood19"				0.5)
			}
		}
	}
	{on blast
		{if min_energy 12
			{ani_play "hit_body_b_frame" 1}	
			(define "cut_min_energy_12"
				{if volume %1
					{tear "piece_medium_steel_crushed" bone %0
						(define "disable_contact_blast_0")
						{impulse up 4 3 dir 7 2 cx 3 2 cy 3 2 rnd_dir 7 no_position}
					}
					{delay 1
						{tags remove "hit_plank_s_%2"}
						{tags remove "hit_plank_m_%2"}
						{tags remove "hit_plank_b_%2"}
						{tags remove "hit_plank_bs_%2"}
						{tags remove "hit_plank_bm_%2"}
					}
				}
			)
			;("cut_min_energy_12" args "frame"		"frame"		frame  	)
			("cut_min_energy_12" args "plank00"		"plank00" 	plank00 )
			("cut_min_energy_12" args "plank01"		"plank01" 	plank01 )
			("cut_min_energy_12" args "plank02"		"plank02" 	plank02 )
			("cut_min_energy_12" args "plank03"		"plank03" 	plank03 )
			("cut_min_energy_12" args "plank04"		"plank04" 	plank04 )
			("cut_min_energy_12" args "plank05"		"plank05"	plank05 )
			("cut_min_energy_12" args "plank06"		"plank06"	plank06 )
			("cut_min_energy_12" args "plank07"		"plank07" 	plank07 )
			("cut_min_energy_12" args "plank08"		"plank08" 	plank08 )
			("cut_min_energy_12" args "plank09"		"plank09" 	plank09 )
			("cut_min_energy_12" args "plank10"		"plank10" 	plank10 )
			("cut_min_energy_12" args "plank11"		"plank11" 	plank11 )
			("cut_min_energy_12" args "plank12"		"plank12" 	plank12 )
			("cut_min_energy_12" args "plank13"		"plank13" 	plank13 )
			("cut_min_energy_12" args "steel00"		"steel00" 	steel00 )
			("cut_min_energy_12" args "steel01"		"steel01" 	steel01 )
			("cut_min_energy_12" args "steel02"		"steel02" 	steel02 )
			("cut_min_energy_12" args "steel03"		"steel03" 	steel03 )
			("cut_min_energy_12" args "steel04"		"steel04" 	steel04 )
			("cut_min_energy_12" args "steel05"		"steel05" 	steel05 )
			("cut_min_energy_12" args "steel06"		"steel06" 	steel06 )
			("cut_min_energy_12" args "steel07"		"steel07" 	steel07 )
			("cut_min_energy_12" args "steel08"		"steel08" 	steel08 )
			("cut_min_energy_12" args "steel09"		"steel09" 	steel09 )
			("cut_min_energy_12" args "steel10"		"steel10" 	steel10 )
			("cut_min_energy_12" args "steel11"		"steel11" 	steel11 )
			("cut_min_energy_12" args "steel12"		"steel12" 	steel12 )
			("cut_min_energy_12" args "steel13"		"steel13" 	steel13 )
			("cut_min_energy_12" args "steel14"		"steel14" 	steel14 )
			("cut_min_energy_12" args "steel15"		"steel15" 	steel15 )
			("cut_min_energy_12" args "steel16"		"steel16" 	steel16 )
			("cut_min_energy_12" args "steel17"		"steel17" 	steel17 )
			("cut_min_energy_12" args "steel18"		"steel18" 	steel18 )
			("cut_min_energy_12" args "steel19"		"steel19" 	steel19 )
			("cut_min_energy_12" args "steel20"		"steel20" 	steel20 )
			("cut_min_energy_12" args "steel21"		"steel21" 	steel21 )
			("cut_min_energy_12" args "steel22"		"steel22" 	steel22 )
			("cut_min_energy_12" args "steel23"		"steel23" 	steel23 )
			("cut_min_energy_12" args "steel24"		"steel24" 	steel24 )
			("cut_min_energy_12" args "steel25"		"steel25" 	steel25 )
			("cut_min_energy_12" args "steel26"		"steel26" 	steel26 )
			("cut_min_energy_12" args "steel27"		"steel27" 	steel27 )
			("cut_min_energy_12" args "steel28"		"steel28" 	steel28 )
			("cut_min_energy_12" args "steel29"		"steel29" 	steel29 )
			("cut_min_energy_12" args "steel30"		"steel30" 	steel30 )
			("cut_min_energy_12" args "steel31"		"steel31" 	steel31 )
			("cut_min_energy_12" args "steel32"		"steel32" 	steel32 )
			("cut_min_energy_12" args "steel33"		"steel33" 	steel33 )
			("cut_min_energy_12" args "iron_sheet00"		"iron_sheet00" 	iron_sheet00 )
			("cut_min_energy_12" args "iron_sheet01"		"iron_sheet01" 	iron_sheet01 )
			("cut_min_energy_12" args "iron_sheet02"		"iron_sheet02" 	iron_sheet02 )
			("cut_min_energy_12" args "iron_sheet03"		"iron_sheet03" 	iron_sheet03 )
			("cut_min_energy_12" args "iron_sheet04"		"iron_sheet04" 	iron_sheet04 )
			("cut_min_energy_12" args "iron_sheet05"		"iron_sheet05" 	iron_sheet05 )
			("cut_min_energy_12" args "iron_sheet06"		"iron_sheet06" 	iron_sheet06 )
			("cut_min_energy_12" args "iron_sheet07"		"iron_sheet07" 	iron_sheet07 )
			("cut_min_energy_12" args "iron_sheet08"		"iron_sheet08" 	iron_sheet08 )
			("cut_min_energy_12" args "iron_sheet09"		"iron_sheet09" 	iron_sheet09 )
			("cut_min_energy_12" args "iron_sheet10"		"iron_sheet10" 	iron_sheet10 )
			("cut_min_energy_12" args "iron_sheet11"		"iron_sheet11" 	iron_sheet11 )
			("cut_min_energy_12" args "iron_sheet12"		"iron_sheet12" 	iron_sheet12 )
			("cut_min_energy_12" args "iron_sheet13"		"iron_sheet13" 	iron_sheet13 )
			("cut_min_energy_12" args "iron_sheet14"		"iron_sheet14" 	iron_sheet14 )
			("cut_min_energy_12" args "iron_sheet15"		"iron_sheet15" 	iron_sheet15 )
			("cut_min_energy_12" args "iron_sheet16"		"iron_sheet16" 	iron_sheet16 )
			("cut_min_energy_12" args "iron_sheet17"		"iron_sheet17" 	iron_sheet17 )
			("cut_min_energy_12" args "iron_sheet18"		"iron_sheet18" 	iron_sheet18 )
			("cut_min_energy_12" args "iron_sheet19"		"iron_sheet19" 	iron_sheet19 )
			("cut_min_energy_12" args "iron_sheet20"		"iron_sheet20" 	iron_sheet20 )
			("cut_min_energy_12" args "iron_sheet21"		"iron_sheet21" 	iron_sheet21 )
			("cut_min_energy_12" args "iron_sheet21"		"iron_sheet21a" 	iron_sheet21a )
			("cut_min_energy_12" args "iron_sheet22"		"iron_sheet22" 	iron_sheet22 )
			("cut_min_energy_12" args "iron_sheet22"		"iron_sheet22a" 	iron_sheet22a )
			("cut_min_energy_12" args "iron_sheet23"		"iron_sheet23" 	iron_sheet23 )
			("cut_min_energy_12" args "iron_sheet24"		"iron_sheet24" 	iron_sheet24 )
			("cut_min_energy_12" args "iron_sheet25"		"iron_sheet25" 	iron_sheet25 )
			("cut_min_energy_12" args "iron_sheet26"		"iron_sheet26" 	iron_sheet26 )
			("cut_min_energy_12" args "iron_sheet27"		"iron_sheet27" 	iron_sheet27 )
			("cut_min_energy_12" args "iron_sheet28"		"iron_sheet28" 	iron_sheet28 )
			("cut_min_energy_12" args "iron_sheet29"		"iron_sheet29" 	iron_sheet29 )
			("cut_min_energy_12" args "iron_sheet30"		"iron_sheet30" 	iron_sheet30 )
			("cut_min_energy_12" args "iron_sheet31"		"iron_sheet31" 	iron_sheet31 )
			("cut_min_energy_12" args "wood00"		"wood00" 	wood00 )
			;("cut_min_energy_12" args "wood01"		"wood01" 	wood01 )
			("cut_min_energy_12" args "wood02"		"wood02" 	wood02 )
			("cut_min_energy_12" args "wood03"		"wood03" 	wood03 )
			("cut_min_energy_12" args "wood04"		"wood04" 	wood04 )
			("cut_min_energy_12" args "wood05"		"wood05" 	wood05 )
			("cut_min_energy_12" args "wood06"		"wood06" 	wood06 )
			("cut_min_energy_12" args "wood07"		"wood07" 	wood07 )
			("cut_min_energy_12" args "wood08"		"wood08" 	wood08 )
			("cut_min_energy_12" args "wood09"		"wood09" 	wood09 )
			("cut_min_energy_12" args "wood10"		"wood10" 	wood10 )
			("cut_min_energy_12" args "wood11"		"wood11" 	wood11 )
			("cut_min_energy_12" args "wood12"		"wood12" 	wood12 )
			("cut_min_energy_12" args "wood13"		"wood13" 	wood13 )
			("cut_min_energy_12" args "wood14"		"wood14" 	wood14 )
			("cut_min_energy_12" args "wood15"		"wood15" 	wood15 )
			("cut_min_energy_12" args "wood16"		"wood16" 	wood16 )
			("cut_min_energy_12" args "wood17"		"wood17" 	wood17 )
			("cut_min_energy_12" args "wood18"		"wood18" 	wood18 )
			("cut_min_energy_12" args "wood19"		"wood19" 	wood19 )
		else min_energy 4
			(define "cut_min_energy_4"
				{if volume %0
					{if not tagged "hit_plank_bm_%3" ;small
						{if not tagged "hit_plank_bs_%3"
							{if not tagged "hit_plank_b_%3"
								{if not tagged "hit_plank_m_%3"
									{if not tagged "hit_plank_s_%3" 
										{tags add "hit_plank_s_%3"}
										{if rand %5
											{delay 0.1
												{ani_play "hit_plank_s_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_plank_s_%3"  ;meds
						{if not tagged "hit_plank_bs_%3"  ;meds
							{if not tagged "hit_plank_bm_%3"
								{if not tagged "hit_plank_b_%3"
									{if not tagged "hit_plank_m_%3" 
										{if rand %4
											{tags add "hit_plank_m_%3"}
											{delay 0.01
												{ani_play "hit_plank_m_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_plank_m_%3"
						{if not tagged "hit_plank_bm_%3" ;big
							{if not tagged "hit_plank_bs_%3"
								{if not tagged "hit_plank_b_%3" 
									{if rand %4
										{tags add "hit_plank_b_%3"}
										{delay 0.01
											{ani_play "hit_plank_b_%3" 1}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_plank_b_%3"
						{if not tagged "hit_plank_bm_%3" ;big small
							{if not tagged "hit_plank_bs_%3"
								{if rand %6
									{tags add "hit_plank_bs_%3"}
									{delay 0.02
										{ani_play "hit_plank_bs_%3" 1}
									}
								}
							}
						}
					}
					{if tagged "hit_plank_bs_%3"
						{if not tagged "hit_plank_bm_%3" ;big meds
							{if rand %7
								{tags add "hit_plank_bm_%3"}
								{delay 0.03
									{ani_play "hit_plank_bm_%3" 1}
								}
							}
						}
					}
				}
				{if volume "tear"
					{if rand 0.5
						{tear "piece_medium_steel_crushed" bone from_volume
							{spawn "spheredust_small_short_arm" %0}
							{impulse up 3 1.5 dir 1 0.5}
						}	
					}	
				}	
				{if rand %2
					{if volume %1
						{if tagged "hit_plank_m_%3"
							{delay 0.01
								{spawn "metal_crush" %0}
								{tear "piece_medium_steel_crushed" bone %0
									{impulse up 1 0.5 dir 1 0.5}
								}
							}
						}
					else volume "frame"
						{set "end_stage" 1}
						{call "end_stage"}		
					}
				}
			)	
			;("cut_min_energy_4" args "frame"		"frame"				0.05	frame  	 0.1  0.3 0.5  0.2 )
			("cut_min_energy_4" args "plank00"		"plank00"			0.01	plank00  0.8  0.98 0.5  0.2)
			("cut_min_energy_4" args "plank01"		"plank01"			0.01	plank01  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "plank02"		"plank02"			0.01	plank02  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "plank03"		"plank03"			0.01	plank03  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "plank04"		"plank04"			0.01	plank04  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "plank05"		"plank05"			0.01	plank05  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "plank06"		"plank06"			0.01	plank06  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "plank07"		"plank07"			0.01	plank07  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "plank08"		"plank08"			0.01	plank08  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "plank09"		"plank09"			0.01	plank09  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "plank10"		"plank10"			0.01	plank10  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "plank11"		"plank11"			0.01	plank11  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "plank12"		"plank12"			0.01	plank12  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "plank13"		"plank13"			0.01	plank13  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "steel00"		"steel00"			0.001		steel00  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "steel01"		"steel01"			0.001		steel01  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "steel02"		"steel02"			0.001		steel02  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "steel03"		"steel03"			0.001		steel03  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "steel04"		"steel04"			0.001		steel04  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "steel05"		"steel05"			0.001		steel05  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "steel06"		"steel06"			0.001		steel06  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "steel07"		"steel07"			0.001		steel07  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "steel08"		"steel08"			0.001		steel08  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "steel09"		"steel09"			0.001		steel09  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "steel10"		"steel10"			0.001		steel10  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "steel11"		"steel11"			0.001		steel11  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "steel12"		"steel12"			0.001		steel12  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "steel13"		"steel13"			0.001		steel13  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "steel14"		"steel14"			0.001		steel14  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "steel15"		"steel15"			0.001		steel15  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "steel16"		"steel16"			0.001		steel16  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "steel17"		"steel17"			0.001		steel17  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "steel18"		"steel18"			0.001		steel18  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "steel19"		"steel19"			0.001		steel19  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "steel20"		"steel20"			0.001		steel20  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "steel21"		"steel21"			0.001		steel21  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "steel22"		"steel22"			0.001		steel22  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "steel23"		"steel23"			0.001		steel23  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "steel24"		"steel24"			0.001		steel24  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "steel25"		"steel25"			0.001		steel25  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "steel26"		"steel26"			0.001		steel26  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "steel27"		"steel27"			0.001		steel27  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "steel28"		"steel28"			0.001		steel28  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "steel29"		"steel29"			0.001		steel29  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "steel30"		"steel30"			0.001		steel30  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "steel31"		"steel31"			0.001		steel31  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "steel32"		"steel32"			0.001		steel32  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "steel33"		"steel33"			0.001		steel33  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "iron_sheet00"		"iron_sheet00"			0.015		iron_sheet00  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "iron_sheet01"		"iron_sheet01"			0.015		iron_sheet01  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "iron_sheet02"		"iron_sheet02"			0.015		iron_sheet02  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "iron_sheet03"		"iron_sheet03"			0.015		iron_sheet03  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "iron_sheet04"		"iron_sheet04"			0.015		iron_sheet04  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "iron_sheet05"		"iron_sheet05"			0.015		iron_sheet05  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "iron_sheet06"		"iron_sheet06"			0.015		iron_sheet06  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "iron_sheet07"		"iron_sheet07"			0.015		iron_sheet07  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "iron_sheet08"		"iron_sheet08"			0.015		iron_sheet08  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "iron_sheet09"		"iron_sheet09"			0.015		iron_sheet09  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "iron_sheet10"		"iron_sheet10"			0.015		iron_sheet10  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "iron_sheet11"		"iron_sheet11"			0.015		iron_sheet11  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "iron_sheet12"		"iron_sheet12"			0.015		iron_sheet12  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "iron_sheet13"		"iron_sheet13"			0.015		iron_sheet13  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "iron_sheet14"		"iron_sheet14"			0.015		iron_sheet14  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "iron_sheet15"		"iron_sheet15"			0.015		iron_sheet15  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "iron_sheet16"		"iron_sheet16"			0.015		iron_sheet16  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "iron_sheet17"		"iron_sheet17"			0.015		iron_sheet17  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "iron_sheet18"		"iron_sheet18"			0.015		iron_sheet18  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "iron_sheet19"		"iron_sheet19"			0.015		iron_sheet19  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "iron_sheet20"		"iron_sheet20"			0.015		iron_sheet20  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "iron_sheet21"		"iron_sheet21"			0.015		iron_sheet21  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "iron_sheet21"		"iron_sheet21a"			0.015		iron_sheet21a  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "iron_sheet22"		"iron_sheet22"			0.015		iron_sheet22  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "iron_sheet22"		"iron_sheet22a"			0.015		iron_sheet22a  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "iron_sheet23"		"iron_sheet23"			0.015		iron_sheet23  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "iron_sheet24"		"iron_sheet24"			0.015		iron_sheet24  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "iron_sheet25"		"iron_sheet25"			0.015		iron_sheet25  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "iron_sheet26"		"iron_sheet26"			0.015		iron_sheet26  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "iron_sheet27"		"iron_sheet27"			0.015		iron_sheet27  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "iron_sheet28"		"iron_sheet28"			0.015		iron_sheet28  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "iron_sheet29"		"iron_sheet29"			0.015		iron_sheet29  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "iron_sheet30"		"iron_sheet30"			0.015		iron_sheet30  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "iron_sheet31"		"iron_sheet31"			0.015		iron_sheet31  0.8  0.98 0.5  0.2 )
			("cut_min_energy_4" args "wood00"		"wood00"			0.01		wood00  0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "wood01"		"wood01"			0.01		wood01  0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "wood02"		"wood02"			0.01		wood02  0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "wood03"		"wood03"			0.01		wood03  0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "wood04"		"wood04"			0.01		wood04  0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "wood05"		"wood05"			0.01		wood05  0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "wood06"		"wood06"			0.01		wood06  0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "wood07"		"wood07"			0.01		wood07  0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "wood08"		"wood08"			0.01		wood08  0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "wood09"		"wood09"			0.01		wood09  0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "wood10"		"wood10"			0.01		wood10  0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "wood11"		"wood11"			0.01		wood11  0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "wood12"		"wood12"			0.01		wood12  0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "wood13"		"wood13"			0.01		wood13  0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "wood14"		"wood14"			0.01		wood14  0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "wood15"		"wood15"			0.01		wood15  0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "wood16"		"wood16"			0.01		wood16  0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "wood17"		"wood17"			0.01		wood17  0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "wood18"		"wood18"			0.01		wood18  0.8  0.98  0.5  0.2)
			("cut_min_energy_4" args "wood19"		"wood19"			0.01		wood19  0.8  0.98  0.5  0.2)
		else min_energy 1.0
			(define "deform_anim"
				{if volume "tear"
					{if rand 0.1
						{tear "piece_medium_steel_crushed" bone from_volume
							{spawn "spheredust_small_short_arm" %0}
							{impulse up 2 1.5 dir 1 0.5}
						}	
					}	
				}	
				{if volume %0
					{if not tagged "hit_plank_bm_%3" ;small
						{if not tagged "hit_plank_bs_%3"
							{if not tagged "hit_plank_b_%3"
								{if not tagged "hit_plank_m_%3"
									{if not tagged "hit_plank_s_%3" 
										{tags add "hit_plank_s_%3"}
										{if rand %5
											{delay 0.1
												{ani_play "hit_plank_s_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_plank_s_%3"  ;meds
						{if not tagged "hit_plank_bs_%3"  ;meds
							{if not tagged "hit_plank_bm_%3"
								{if not tagged "hit_plank_b_%3"
									{if not tagged "hit_plank_m_%3" 
										{if rand %4
											{tags add "hit_plank_m_%3"}
											{delay 0.01
												{ani_play "hit_plank_m_%3" 1}
											}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_plank_m_%3"
						{if not tagged "hit_plank_bm_%3" ;big
							{if not tagged "hit_plank_bs_%3"
								{if not tagged "hit_plank_b_%3" 
									{if rand %4
										{tags add "hit_plank_b_%3"}
										{delay 0.01
											{ani_play "hit_plank_b_%3" 1}
										}
									}
								}
							}
						}
					}
					{if tagged "hit_plank_b_%3"
						{if not tagged "hit_plank_bm_%3" ;big small
							{if not tagged "hit_plank_bs_%3"
								{if rand %6
									{tags add "hit_plank_bs_%3"}
									{delay 0.02
										{ani_play "hit_plank_bs_%3" 1}
									}
								}
							}
						}
					}
					{if tagged "hit_plank_bs_%3"
						{if not tagged "hit_plank_bm_%3" ;big meds
							{if rand %7
								{tags add "hit_plank_bm_%3"}
								{delay 0.03
									{ani_play "hit_plank_bm_%3" 1}
								}
							}
						}
					}
				}
				{if rand %2
					{if volume %1
						{if tagged "hit_plank_m_%3"
							{delay 0.01
								{spawn "metal_crush" %0}
								{tear "piece_medium_steel_crushed" bone %0
									{impulse up 1 0.5 dir 1 0.5}
								}
							}
						}
					else volume "frame"
						{set "end_stage" 1}
						{call "end_stage"}		
					}
				}
			)	
			;("deform_anim" args "frame"		"frame"				0.05	frame  	 0.1  0.3 0.5  0.2 )
			("deform_anim" args "plank00"		"plank00"			0.01	plank00  0.8  0.98 0.5  0.2)
			("deform_anim" args "plank01"		"plank01"			0.01	plank01  0.8  0.98 0.5  0.2 )
			("deform_anim" args "plank02"		"plank02"			0.01	plank02  0.8  0.98 0.5  0.2 )
			("deform_anim" args "plank03"		"plank03"			0.01	plank03  0.8  0.98 0.5  0.2 )
			("deform_anim" args "plank04"		"plank04"			0.01	plank04  0.8  0.98 0.5  0.2 )
			("deform_anim" args "plank05"		"plank05"			0.01	plank05  0.8  0.98 0.5  0.2 )
			("deform_anim" args "plank06"		"plank06"			0.01	plank06  0.8  0.98 0.5  0.2 )
			("deform_anim" args "plank07"		"plank07"			0.01	plank07  0.8  0.98 0.5  0.2 )
			("deform_anim" args "plank08"		"plank08"			0.01	plank08  0.8  0.98 0.5  0.2 )
			("deform_anim" args "plank09"		"plank09"			0.01	plank09  0.8  0.98 0.5  0.2 )
			("deform_anim" args "plank10"		"plank10"			0.01	plank10  0.8  0.98 0.5  0.2 )
			("deform_anim" args "plank11"		"plank11"			0.01	plank11  0.8  0.98 0.5  0.2 )
			("deform_anim" args "plank12"		"plank12"			0.01	plank12  0.8  0.98 0.5  0.2 )
			("deform_anim" args "plank13"		"plank13"			0.01	plank13  0.8  0.98 0.5  0.2 )
			("deform_anim" args "steel00"		"steel00"			0.001		steel00  0.8  0.98 0.5  0.2 )
			("deform_anim" args "steel01"		"steel01"			0.001		steel01  0.8  0.98 0.5  0.2 )
			("deform_anim" args "steel02"		"steel02"			0.001		steel02  0.8  0.98 0.5  0.2 )
			("deform_anim" args "steel03"		"steel03"			0.001		steel03  0.8  0.98 0.5  0.2 )
			("deform_anim" args "steel04"		"steel04"			0.001		steel04  0.8  0.98 0.5  0.2 )
			("deform_anim" args "steel05"		"steel05"			0.001		steel05  0.8  0.98 0.5  0.2 )
			("deform_anim" args "steel06"		"steel06"			0.001		steel06  0.8  0.98 0.5  0.2 )
			("deform_anim" args "steel07"		"steel07"			0.001		steel07  0.8  0.98 0.5  0.2 )
			("deform_anim" args "steel08"		"steel08"			0.001		steel08  0.8  0.98 0.5  0.2 )
			("deform_anim" args "steel09"		"steel09"			0.001		steel09  0.8  0.98 0.5  0.2 )
			("deform_anim" args "steel10"		"steel10"			0.001		steel10  0.8  0.98 0.5  0.2 )
			("deform_anim" args "steel11"		"steel11"			0.001		steel11  0.8  0.98 0.5  0.2 )
			("deform_anim" args "steel12"		"steel12"			0.001		steel12  0.8  0.98 0.5  0.2 )
			("deform_anim" args "steel13"		"steel13"			0.001		steel13  0.8  0.98 0.5  0.2 )
			("deform_anim" args "steel14"		"steel14"			0.001		steel14  0.8  0.98 0.5  0.2 )
			("deform_anim" args "steel15"		"steel15"			0.001		steel15  0.8  0.98 0.5  0.2 )
			("deform_anim" args "steel16"		"steel16"			0.001		steel16  0.8  0.98 0.5  0.2 )
			("deform_anim" args "steel17"		"steel17"			0.001		steel17  0.8  0.98 0.5  0.2 )
			("deform_anim" args "steel18"		"steel18"			0.001		steel18  0.8  0.98 0.5  0.2 )
			("deform_anim" args "steel19"		"steel19"			0.001		steel19  0.8  0.98 0.5  0.2 )
			("deform_anim" args "steel20"		"steel20"			0.001		steel20  0.8  0.98 0.5  0.2 )
			("deform_anim" args "steel21"		"steel21"			0.001		steel21  0.8  0.98 0.5  0.2 )
			("deform_anim" args "steel22"		"steel22"			0.001		steel22  0.8  0.98 0.5  0.2 )
			("deform_anim" args "steel23"		"steel23"			0.001		steel23  0.8  0.98 0.5  0.2 )
			("deform_anim" args "steel24"		"steel24"			0.001		steel24  0.8  0.98 0.5  0.2 )
			("deform_anim" args "steel25"		"steel25"			0.001		steel25  0.8  0.98 0.5  0.2 )
			("deform_anim" args "steel26"		"steel26"			0.001		steel26  0.8  0.98 0.5  0.2 )
			("deform_anim" args "steel27"		"steel27"			0.001		steel27  0.8  0.98 0.5  0.2 )
			("deform_anim" args "steel28"		"steel28"			0.001		steel28  0.8  0.98 0.5  0.2 )
			("deform_anim" args "steel29"		"steel29"			0.001		steel29  0.8  0.98 0.5  0.2 )
			("deform_anim" args "steel30"		"steel30"			0.001		steel30  0.8  0.98 0.5  0.2 )
			("deform_anim" args "steel31"		"steel31"			0.001		steel31  0.8  0.98 0.5  0.2 )
			("deform_anim" args "steel32"		"steel32"			0.001		steel32  0.8  0.98 0.5  0.2 )
			("deform_anim" args "steel33"		"steel33"			0.001		steel33  0.8  0.98 0.5  0.2 )
			("deform_anim" args "iron_sheet00"		"iron_sheet00"			0.015		iron_sheet00  0.8  0.98 0.5  0.2 )
			("deform_anim" args "iron_sheet01"		"iron_sheet01"			0.015		iron_sheet01  0.8  0.98 0.5  0.2 )
			("deform_anim" args "iron_sheet02"		"iron_sheet02"			0.015		iron_sheet02  0.8  0.98 0.5  0.2 )
			("deform_anim" args "iron_sheet03"		"iron_sheet03"			0.015		iron_sheet03  0.8  0.98 0.5  0.2 )
			("deform_anim" args "iron_sheet04"		"iron_sheet04"			0.015		iron_sheet04  0.8  0.98 0.5  0.2 )
			("deform_anim" args "iron_sheet05"		"iron_sheet05"			0.015		iron_sheet05  0.8  0.98 0.5  0.2 )
			("deform_anim" args "iron_sheet06"		"iron_sheet06"			0.015		iron_sheet06  0.8  0.98 0.5  0.2 )
			("deform_anim" args "iron_sheet07"		"iron_sheet07"			0.015		iron_sheet07  0.8  0.98 0.5  0.2 )
			("deform_anim" args "iron_sheet08"		"iron_sheet08"			0.015		iron_sheet08  0.8  0.98 0.5  0.2 )
			("deform_anim" args "iron_sheet09"		"iron_sheet09"			0.015		iron_sheet09  0.8  0.98 0.5  0.2 )
			("deform_anim" args "iron_sheet10"		"iron_sheet10"			0.015		iron_sheet10  0.8  0.98 0.5  0.2 )
			("deform_anim" args "iron_sheet11"		"iron_sheet11"			0.015		iron_sheet11  0.8  0.98 0.5  0.2 )
			("deform_anim" args "iron_sheet12"		"iron_sheet12"			0.015		iron_sheet12  0.8  0.98 0.5  0.2 )
			("deform_anim" args "iron_sheet13"		"iron_sheet13"			0.015		iron_sheet13  0.8  0.98 0.5  0.2 )
			("deform_anim" args "iron_sheet14"		"iron_sheet14"			0.015		iron_sheet14  0.8  0.98 0.5  0.2 )
			("deform_anim" args "iron_sheet15"		"iron_sheet15"			0.015		iron_sheet15  0.8  0.98 0.5  0.2 )
			("deform_anim" args "iron_sheet16"		"iron_sheet16"			0.015		iron_sheet16  0.8  0.98 0.5  0.2 )
			("deform_anim" args "iron_sheet17"		"iron_sheet17"			0.015		iron_sheet17  0.8  0.98 0.5  0.2 )
			("deform_anim" args "iron_sheet18"		"iron_sheet18"			0.015		iron_sheet18  0.8  0.98 0.5  0.2 )
			("deform_anim" args "iron_sheet19"		"iron_sheet19"			0.015		iron_sheet19  0.8  0.98 0.5  0.2 )
			("deform_anim" args "iron_sheet20"		"iron_sheet20"			0.015		iron_sheet20  0.8  0.98 0.5  0.2 )
			("deform_anim" args "iron_sheet21"		"iron_sheet21"			0.015		iron_sheet21  0.8  0.98 0.5  0.2 )
			("deform_anim" args "iron_sheet21"		"iron_sheet21a"			0.015		iron_sheet21a  0.8  0.98 0.5  0.2 )
			("deform_anim" args "iron_sheet22"		"iron_sheet22"			0.015		iron_sheet22  0.8  0.98 0.5  0.2 )
			("deform_anim" args "iron_sheet22"		"iron_sheet22a"			0.015		iron_sheet22a  0.8  0.98 0.5  0.2 )
			("deform_anim" args "iron_sheet23"		"iron_sheet23"			0.015		iron_sheet23  0.8  0.98 0.5  0.2 )
			("deform_anim" args "iron_sheet24"		"iron_sheet24"			0.015		iron_sheet24  0.8  0.98 0.5  0.2 )
			("deform_anim" args "iron_sheet25"		"iron_sheet25"			0.015		iron_sheet25  0.8  0.98 0.5  0.2 )
			("deform_anim" args "iron_sheet26"		"iron_sheet26"			0.015		iron_sheet26  0.8  0.98 0.5  0.2 )
			("deform_anim" args "iron_sheet27"		"iron_sheet27"			0.015		iron_sheet27  0.8  0.98 0.5  0.2 )
			("deform_anim" args "iron_sheet28"		"iron_sheet28"			0.015		iron_sheet28  0.8  0.98 0.5  0.2 )
			("deform_anim" args "iron_sheet29"		"iron_sheet29"			0.015		iron_sheet29  0.8  0.98 0.5  0.2 )
			("deform_anim" args "iron_sheet30"		"iron_sheet30"			0.015		iron_sheet30  0.8  0.98 0.5  0.2 )
			("deform_anim" args "iron_sheet31"		"iron_sheet31"			0.015		iron_sheet31  0.8  0.98 0.5  0.2 )
			("deform_anim" args "wood00"		"wood00"			0.01		wood00  0.8  0.98  0.5  0.2)
			("deform_anim" args "wood01"		"wood01"			0.01		wood01  0.8  0.98  0.5  0.2)
			("deform_anim" args "wood02"		"wood02"			0.01		wood02  0.8  0.98  0.5  0.2)
			("deform_anim" args "wood03"		"wood03"			0.01		wood03  0.8  0.98  0.5  0.2)
			("deform_anim" args "wood04"		"wood04"			0.01		wood04  0.8  0.98  0.5  0.2)
			("deform_anim" args "wood05"		"wood05"			0.01		wood05  0.8  0.98  0.5  0.2)
			("deform_anim" args "wood06"		"wood06"			0.01		wood06  0.8  0.98  0.5  0.2)
			("deform_anim" args "wood07"		"wood07"			0.01		wood07  0.8  0.98  0.5  0.2)
			("deform_anim" args "wood08"		"wood08"			0.01		wood08  0.8  0.98  0.5  0.2)
			("deform_anim" args "wood09"		"wood09"			0.01		wood09  0.8  0.98  0.5  0.2)
			("deform_anim" args "wood10"		"wood10"			0.01		wood10  0.8  0.98  0.5  0.2)
			("deform_anim" args "wood11"		"wood11"			0.01		wood11  0.8  0.98  0.5  0.2)
			("deform_anim" args "wood12"		"wood12"			0.01		wood12  0.8  0.98  0.5  0.2)
			("deform_anim" args "wood13"		"wood13"			0.01		wood13  0.8  0.98  0.5  0.2)
			("deform_anim" args "wood14"		"wood14"			0.01		wood14  0.8  0.98  0.5  0.2)
			("deform_anim" args "wood15"		"wood15"			0.01		wood15  0.8  0.98  0.5  0.2)
			("deform_anim" args "wood16"		"wood16"			0.01		wood16  0.8  0.98  0.5  0.2)
			("deform_anim" args "wood17"		"wood17"			0.01		wood17  0.8  0.98  0.5  0.2)
			("deform_anim" args "wood18"		"wood18"			0.01		wood18  0.8  0.98  0.5  0.2)
			("deform_anim" args "wood19"		"wood19"			0.01		wood19  0.8  0.98  0.5  0.2)
		}
	}
	{on bullet_hit
		{if stuff "fx_40"
			{bullet_detonate}
		}
	}
	{on "end_stage"
		{if "end_stage"
			(define "cut_part"
				{if rand %1
					{tear "piece_small_steel" bone %0
						{impulse up 0.1 dir 0.1}
					}
				}
			)	
			("cut_part" args "iron_sheet00"				0.0001)
			("cut_part" args "iron_sheet01"				0.0001)
			("cut_part" args "iron_sheet02"				0.0001)
			("cut_part" args "iron_sheet03"				0.0001)
			("cut_part" args "iron_sheet04"				0.0001)
			("cut_part" args "iron_sheet05"				0.0001)
			("cut_part" args "iron_sheet06"				0.0001)
			("cut_part" args "iron_sheet07"				0.0001)
			("cut_part" args "iron_sheet08"				0.0001)
			("cut_part" args "iron_sheet09"				0.0001)
			("cut_part" args "iron_sheet10"				0.0001)
			("cut_part" args "iron_sheet11"				0.0001)
			("cut_part" args "iron_sheet12"				0.0001)
			("cut_part" args "iron_sheet13"				0.0001)
			("cut_part" args "iron_sheet14"				0.0001)
			("cut_part" args "iron_sheet15"				0.0001)
			("cut_part" args "iron_sheet16"				0.0001)
			("cut_part" args "iron_sheet17"				0.0001)
			("cut_part" args "iron_sheet18"				0.0001)
			("cut_part" args "iron_sheet19"				0.0001)
			("cut_part" args "iron_sheet20"				0.0001)
			("cut_part" args "iron_sheet21"				0.0001)
			("cut_part" args "iron_sheet22"				0.0001)
			("cut_part" args "iron_sheet23"				0.0001)
			("cut_part" args "iron_sheet24"				0.0001)
			("cut_part" args "iron_sheet25"				0.0001)
			("cut_part" args "iron_sheet26"				0.0001)
			("cut_part" args "iron_sheet27"				0.0001)
			("cut_part" args "iron_sheet28"				0.0001)
			("cut_part" args "iron_sheet29"				0.0001)
			("cut_part" args "iron_sheet30"				0.0001)
			("cut_part" args "iron_sheet31"				0.0001)
		}
	}
}

{"metals_build_heavy"
	{on pierce sync
		(define "cut_part"
			{if rand %2
				{if volume %1
					{tear "piece_medium_steel_crushed" bone %0
						{spawn "metal_crush" %0}
						{impulse up 1 0.5 dir 1 0.5}
					}
				else volume "frame"
					{if rand 0.1
						{tear "piece_medium_steel_crushed" bone %0
							{spawn "metal_crush" %0}
							{impulse up 1 0.5 dir 1 0.5}
						}
						{set "end_stage" 1}
						{call "end_stage"}
					}
				}
			}
		)	
		("cut_part" args "hpanel"		"hpanel"			0.1)
		("cut_part" args "steel01"		"steel01"			0.7)
		("cut_part" args "steel02"		"steel02"			0.7)
		("cut_part" args "steel03"		"steel03"			0.2)
		("cut_part" args "steel04"		"steel04"			0.2)
		("cut_part" args "steel05"		"steel05"			0.2)
		("cut_part" args "steel06"		"steel06"			0.2)
		("cut_part" args "steel07"		"steel07"			0.2)
		("cut_part" args "steel08"		"steel08"			0.2)
		("cut_part" args "steel09"		"steel09"			0.2)
		("cut_part" args "steel10"		"steel10"			0.2)
		("cut_part" args "steel00"		"steel00"			0.2)
	}
	{on blast_hit
		{if min_energy 12
			(define "cut_part"
				{tear "piece_medium_steel_crushed" bone %0
					{impulse up 5 3 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
				}
			)
			("cut_part" args "hpanel"		"hpanel" )
			("cut_part" args "steel01"		"steel01"			)
			("cut_part" args "steel02"		"steel02"			)
			("cut_part" args "steel03"		"steel03"			)
			("cut_part" args "steel04"		"steel04"			)
			("cut_part" args "steel05"		"steel05"			)
			("cut_part" args "steel06"		"steel06"			)
			("cut_part" args "steel07"		"steel07"			)
			("cut_part" args "steel08"		"steel08"			)
			("cut_part" args "steel09"		"steel09"			)
			("cut_part" args "steel10"		"steel10"			)
			("cut_part" args "steel00"		"steel00"			)
		}
	}
	{on "end_stage"
		{if "end_stage"
			(define "cut_part"
				{if rand %1
					{tear "piece_small_steel" bone %0
						{impulse up 0.1 dir 0.1}
					}
				}
			)	
			("cut_part" args "steel01"							0.7)
			("cut_part" args "steel02"							0.7)
			("cut_part" args "hpanel"							0.3)
			("cut_part" args "steel00"							0.3)
		}
	}
}

{"concrete small parts construction"
	{on "cut_pieces"
		{volumes disable contact}
		(define "cut_piece"
			{tear "piece_small_concrete" bone "piece%0"
				{volumes enable contact}
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
			}
		)
		("cut_pieces")
	}
}

{"concrete small parts construction big_impulse"
	{on "cut_pieces" overload
		{if "blast"
			{volumes disable contact}
			(define "cut_piece"
				{tear "piece_small_concrete" bone "piece%0"
					{volumes enable contact}
					{impulse up 5 2 dir 3.5 2.5 rnd_dir 5 no_position}
				}
			)
			("cut_pieces")
		else
			{inherited}
		}
	}
}

{"big steel parts construction"
	{on "cut_pieces"
		(define "cut_piece"
			{tear "piece_large_steel" bone "piece%0"
				{volumes enable contact}
				{impulse up 2.5 1.7 dir 3.5 1.3 no_position}
			}
		)
		("cut_pieces")
		(define "cut_subpiece"
			{tear "piece_medium_steel_crushed" bone "sub_piece%0"
				{volumes enable contact}
				{spawn "spheredust_norm" "sub_piece%0"}
				{impulse up 2.5 1.7 dir 3.5 1.3 no_position}
			}
		)
		("cut_subpieces")
	}
}

{"small steel parts construction"
	{on "cut_pieces"
		{volumes disable contact}
		(define "cut_piece"
			{tear "piece_medium_steel_crushed" bone "piece%0"
				{volumes enable contact}
				{if "blast"
					{impulse up 4 2 dir 2.5 1.3 no_position}
				else
					{impulse up 1 0.7 dir -4.5 0.3 no_position}
				}
			}
		)
		("cut_pieces")
	}
}

{"wood parts construction"
	{on bullet_hit
		{if volume "body"
			{if stuff "shell"
				{set "blast" 0}
				{call "change_model"}
			}
		}
	}
	{on "cut_pieces"
		(define "cut_piece"
			{tear "building_part_wood" bone "piece%0"
				{volumes enable contact float}
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
			}
		)
		("cut_pieces")
	}
}

{"small wood parts construction"
	{on "cut_pieces" overload
		{volumes disable contact blast}
		(define "cut_piece"
			{tear "piece_small_wood" bone "piece%0"
				{volumes enable float}
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
			}
		)
		("cut_pieces")
	}
}

{"small wood parts construction big_impulse"
	{on "cut_pieces" overload
		{if "blast"
			{volumes disable contact blast}
			(define "cut_piece"
				{tear "piece_small_wood" bone "piece%0"
					{volumes enable float}
					{impulse up 5 2 dir 3.5 2.5 rnd_dir 5 no_position}
				}
			)
			("cut_pieces")
		else
			{inherited}
		}
	}
}

{"small sand parts construction"
	{on "cut_pieces" overload
		{volumes disable contact blast}
		(define "cut_piece"
			{tear "piece_medium_sand" bone "piece%0"
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
			}
		)
		("cut_pieces")
	}
}

{"piece_large_concrete"
	{on spawn
		{if rand 0.5
			{set "crush" 1}
		}
	}
	{on ground_hit sync
		{if "crush"
			{spawn "piece_crush"}
			{delete}
		}
	}
	{on contact sync
		{if can_crush
			{spawn "piece_crush"}
			{delete}
		}
	}
}

{"building_part"
	{on spawn
		{if rand 0.5
			{set "crush" 1}
		}
	}
	{on ground_hit sync
		{if not "sliced"
			{spawn "spheredust_big_short"}
			{call "cut_subpieces"}
		}
	}
	{on contact sync
		{if not "sliced"
			{spawn "spheredust_big_short"}
			{call "cut_subpieces"}
		}
	}
}

{"building_part concrete"
	{on ground_hit sync
		{if "crush"
			{spawn "piece_crush_big"}
			{delete}
		}
	}
	{on contact sync
		{if can_crush
			{spawn "piece_crush_big"}
			{delete}
		}
	}
	{on "cut_subpieces"
		{set "sliced" 1}
		(define "cut_subpiece"
			{tear "piece_large_concrete" bone "sub_piece%0" id "building_part_concrete_subpiece"
				{volumes enable contact}
				{spawn "spheredust_norm" "sub_piece%0"}
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
				{add_view "smoke_black" "smoke" "root"}
				{view start "smoke"}
				{delay_effect 1 0.5 "stop"}
			}
		)
		("cut_subpieces")
	}
	{on "slice_load"
		{if name "building_part_concrete_subpiece"
			{with_effector
				{add_view "smoke_black" "smoke" "root"}
			}
		}
	}
}

{"building_part wood"
	{on "cut_subpieces"
		{set "sliced" 1}
		(define "cut_subpiece"
			{tear "piece_big_wood" bone "sub_piece%0" id "building_part_wood_subpiece"
				{volumes enable contact}
				{spawn "spheredust_norm" "sub_piece%0"}
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
				{add_view "smoke_black" "smoke" "root"}
				{view start "smoke"}
				{delay_effect 5 3 "stop"}
			}
		)
		("cut_subpieces")
	}
	{on contact sync
		{if can_crush
			{spawn "wood_hit_small"}
			{delete}
		}
	}
	{on "slice_load"
		{if name "building_part_wood_subpiece"
			{with_effector
				{add_view "smoke_black" "smoke" "root"}
			}
		}
	}
}

{"cornered parts construction"
	{on bullet_hit
		{if not under_water
			{if stuff "shell small"
				{spawn	"stone_hit_br_small" inv_normal}
			else stuff "big shell fg"
				{spawn	"stone_hit_br_big" inv_normal}
			else stuff "shell"
				{spawn	"stone_hit_br" inv_normal}
			}
		}
	}
	{on "cut_pieces"
		(define "cut_piece"
			{tear "building_part_concrete" bone "piece%0"
				{volumes enable contact}
				{impulse up 1 0.7 dir -5 1.3 no_position}
				{spawn "spheredust_norm" "piece%0"}
			}
		)
		("cut_pieces")
		(define "cut_subpiece"
			{tear "piece_large_concrete" bone "sub_piece%0" id "cornered_parts_construction_piece"
				{volumes enable contact}
				{spawn "spheredust_norm" "sub_piece%0"}
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
			}
		)
		("cut_subpieces")
	}
	{on "slice_load"
		{if name "cornered_parts_construction_piece"
			{with_effector
				{add_view "smoke_black" "smoke" "root"}
			}
		}
	}
	{on "destroyed_stamp" overload
		{if rand 0.25
			{spawn "crash_brick3"	random_position 20}
		else rand 0.25
			{spawn "stonechip1"		random_position 20}
		else rand 0.25
			{spawn "crash_stone2"	random_position 20}
		else
			{spawn "crash_brick3a"	random_position 20}
		}
	}
}

{"no_slices wall cornered parts construction"
	{on "effects"
		{start_sound "crush/big/concrete"}
	}
}

{"wall cornered parts construction"
	{on "effects"
		{start_sound "crush/medium/concrete"}
	}
	{on contact sync
		{if can_crush
			{if effector "small_auto"
				{if min_speed 25
					{if rand 0.4
						{set "blast" 0}
						{call "change_model"}
					}
				}
			else
				{set "blast" 0}
				{call "change_model"}
			}
		}
	}
}

{"small cornered parts construction"
	{on "effects"
		{start_sound "crush/small/concrete"}
	}
}

{"unbreakable parts construction"
	{on break_armor overload}
	{on "destroyed_stamp" overload}
}

{"ice parts construction"
	{on overlap begin
		{if not tagged "strong"
			{set "blast" 0}
			{if effector "tank"
				{call "delayed_change_model"}
			else effector "car"
				{call "delayed_change_model"}
			}
		}
	}
	{on "delayed_change_model"
		{if not "delayed_change_model"
			{set "delayed_change_model" 1}
			{delay 2
				{call "change_model"}
			}
		}
	}
	{on contact sync overload}
	{on "cut_pieces"
		{volumes "body" disable overlap blast}
		{spawn "iceblock_hit01"}
		{delay 0.5
			{spawn "ex_water_sm"}
		}
		(define "cut_piece"
			{tear "piece_medium_ice" bone "piece%0"
				{volumes enable contact}
				{impulse up 1 0.7 dir 2.5 0.3 no_position}
			}
		)
		("cut_pieces")
	}
}

{"wood_build"
	{on "burn_volume"
		{if not "burned"
			{set "burned" 1}
			{if volume "fire"
				{call "_burns"}
			}
		}
	}
	{on "_burns"
		{fire radius 0.3 time 40 heating 3}
		{burn volume fx "smoke_dead_norm" time 37 fake even_law}
		{burn volume fx "smoke_camp_storeable" time 54 fake even_law}
		{delay 8 2 "burn_die1"
			{tex_morph "d" 5}
			{call "_burn_crash"}
			{delay 6 "_burn_crash_end"
				{call "_burn_crash_end"}
			}
			{delay 12 3 "burn_die2"
				{call "_burn_crash"}
				{delay 16 2 "burn_die3"
					{tex_morph "b" 12}
					{call "_burn_crash"}
				}
			}
		}
	}
	{on "_burn_crash"
		{start_sound "crush/small/wood/"}
		(define "_burn_crash"
			{if rand %1
				{tear "piece_small_wood" bone %0
					{impulse up 0.3 dir 0.3}
				}
			}
		)	
		("_burn_crash" args "wood00"			0.4)
		("_burn_crash" args "wood01"			0.4)
		("_burn_crash" args "wood02"			0.4)
		("_burn_crash" args "wood03"			0.4)
		("_burn_crash" args "wood04"			0.4)
		("_burn_crash" args "wood05"			0.4)
		("_burn_crash" args "wood06"			0.4)
		("_burn_crash" args "wood07"			0.4)
		("_burn_crash" args "wood08"			0.4)
		("_burn_crash" args "wood_frame00"		0.1)
		("_burn_crash" args "wood_frame01"		0.1)
		("_burn_crash" args "wood_frame02"		0.1)
		("_burn_crash" args "wood_frame03"		0.1)
		("_burn_crash" args "wood_frame04"		0.1)
		("_burn_crash" args "wood_frame05"		0.1)
		("_burn_crash" args "wood_frame06"		0.1)
	}
	{on "_burn_crash_end"
		{delay 18
		{start_sound "crush/small/wood/"}
		(define "_burn_crash"
			{if rand %1
				{tear "piece_small_wood" bone %0
					{impulse up 0.3 dir 0.3}
				}
			}
		)	
		("_burn_crash" args "wood00"			0.7)
		("_burn_crash" args "wood01"			0.7)
		("_burn_crash" args "wood02"			0.7)
		("_burn_crash" args "wood03"			0.7)
		("_burn_crash" args "wood04"			0.7)
		("_burn_crash" args "wood05"			0.7)
		("_burn_crash" args "wood06"			0.7)
		("_burn_crash" args "wood07"			0.7)
		("_burn_crash" args "wood08"			0.7)
		("_burn_crash" args "wood_frame00"		0.5)
		("_burn_crash" args "wood_frame01"		0.5)
		("_burn_crash" args "wood_frame02"		0.5)
		("_burn_crash" args "wood_frame03"		0.5)
		("_burn_crash" args "wood_frame04"		0.5)
		("_burn_crash" args "wood_frame05"		0.5)
		("_burn_crash" args "wood_frame06"		0.5)
	}
	}
	{on pierce sync
		{if stuff "shell"
			(define "cut_part"
				{if rand %2
					{if volume %1
						{tear "piece_small_wood" bone %0
							{impulse up 2 0.5 dir 2 0.5}
						}
					}
				}
			)	
			("cut_part" args "wood00"		"wood00"			0.9)
			("cut_part" args "wood01"		"wood01"			0.9)
			("cut_part" args "wood02"		"wood02"			0.9)
			("cut_part" args "wood03"		"wood03"			0.9)
			("cut_part" args "wood04"		"wood04"			0.9)
			("cut_part" args "wood05"		"wood05"			0.9)
			("cut_part" args "wood06"		"wood06"			0.9)
			("cut_part" args "wood07"		"wood07"			0.9)
			("cut_part" args "wood08"		"wood08"			0.9)
			("cut_part" args "wood_frame00"		"wood_frame00"			0.9)
			("cut_part" args "wood_frame01"		"wood_frame01"			0.9)
			("cut_part" args "wood_frame02"		"wood_frame02"			0.9)
			("cut_part" args "wood_frame03"		"wood_frame03"			0.9)
			("cut_part" args "wood_frame04"		"wood_frame04"			0.9)
			("cut_part" args "wood_frame05"		"wood_frame05"			0.9)
			("cut_part" args "wood_frame06"		"wood_frame06"			0.9)
		else stuff "shell_minimum"
			(define "cut_part"
				{if rand %2
					{if volume %1
						{tear "piece_small_wood" bone %0
							{impulse up 3 0.5 dir 1 0.5}
						}
					}
				}
			)	
			("cut_part" args "wood00"		"wood00"			0.7)
			("cut_part" args "wood01"		"wood01"			0.7)
			("cut_part" args "wood02"		"wood02"			0.7)
			("cut_part" args "wood03"		"wood03"			0.7)
			("cut_part" args "wood04"		"wood04"			0.7)
			("cut_part" args "wood05"		"wood05"			0.7)
			("cut_part" args "wood06"		"wood06"			0.7)
			("cut_part" args "wood07"		"wood07"			0.7)
			("cut_part" args "wood08"		"wood08"			0.7)
			("cut_part" args "wood_frame00"		"wood_frame00"			0.7)
			("cut_part" args "wood_frame01"		"wood_frame01"			0.7)
			("cut_part" args "wood_frame02"		"wood_frame02"			0.7)
			("cut_part" args "wood_frame03"		"wood_frame03"			0.7)
			("cut_part" args "wood_frame04"		"wood_frame04"			0.7)
			("cut_part" args "wood_frame05"		"wood_frame05"			0.7)
			("cut_part" args "wood_frame06"		"wood_frame06"			0.7)
		else stuff "fx_40"
			(define "cut_part"
				{if rand %2
					{if volume %1
						{tear "piece_small_wood" bone %0
							{impulse up 3 0.5 dir 1 0.5}
						}
					}
				}
			)	
			("cut_part" args "wood00"		"wood00"			0.9)
			("cut_part" args "wood01"		"wood01"			0.9)
			("cut_part" args "wood02"		"wood02"			0.9)
			("cut_part" args "wood03"		"wood03"			0.9)
			("cut_part" args "wood04"		"wood04"			0.9)
			("cut_part" args "wood05"		"wood05"			0.9)
			("cut_part" args "wood06"		"wood06"			0.9)
			("cut_part" args "wood07"		"wood07"			0.9)
			("cut_part" args "wood08"		"wood08"			0.9)
			("cut_part" args "wood_frame00"		"wood_frame00"			0.9)
			("cut_part" args "wood_frame01"		"wood_frame01"			0.9)
			("cut_part" args "wood_frame02"		"wood_frame02"			0.9)
			("cut_part" args "wood_frame03"		"wood_frame03"			0.9)
			("cut_part" args "wood_frame04"		"wood_frame04"			0.9)
			("cut_part" args "wood_frame05"		"wood_frame05"			0.9)
			("cut_part" args "wood_frame06"		"wood_frame06"			0.9)
		else stuff "bullet"
			(define "cut_part"
				{if rand %2
					{if volume %1
						{tear "piece_small_wood" bone %0
							{impulse up 1 0.5 dir 1 0.5}
						}
					}
				}
			)	
			("cut_part" args "wood00"		"wood00"			0.2)
			("cut_part" args "wood01"		"wood01"			0.2)
			("cut_part" args "wood02"		"wood02"			0.2)
			("cut_part" args "wood03"		"wood03"			0.2)
			("cut_part" args "wood04"		"wood04"			0.2)
			("cut_part" args "wood05"		"wood05"			0.2)
			("cut_part" args "wood06"		"wood06"			0.2)
			("cut_part" args "wood07"		"wood07"			0.2)
			("cut_part" args "wood08"		"wood08"			0.2)
			("cut_part" args "wood_frame00"		"wood_frame00"			0.1)
			("cut_part" args "wood_frame01"		"wood_frame01"			0.1)
			("cut_part" args "wood_frame02"		"wood_frame02"			0.1)
			("cut_part" args "wood_frame03"		"wood_frame03"			0.1)
			("cut_part" args "wood_frame04"		"wood_frame04"			0.1)
			("cut_part" args "wood_frame05"		"wood_frame05"			0.1)
			("cut_part" args "wood_frame06"		"wood_frame06"			0.1)
		}
	}
	{on blast_hit
		{if min_energy 2
			(define "cut_part"
				{if rand %2
					{if volume %1
						{tear "piece_small_wood" bone %0
							{impulse up 3 2 dir 3 1}
						}
					}
				}
			)	
			("cut_part" args "wood00"		"wood00"			0.7)
			("cut_part" args "wood01"		"wood01"			0.7)
			("cut_part" args "wood02"		"wood02"			0.7)
			("cut_part" args "wood03"		"wood03"			0.7)
			("cut_part" args "wood04"		"wood04"			0.7)
			("cut_part" args "wood05"		"wood05"			0.7)
			("cut_part" args "wood06"		"wood06"			0.7)
			("cut_part" args "wood07"		"wood07"			0.7)
			("cut_part" args "wood08"		"wood08"			0.7)
			("cut_part" args "wood_frame00"		"wood_frame00"			0.3)
			("cut_part" args "wood_frame01"		"wood_frame01"			0.3)
			("cut_part" args "wood_frame02"		"wood_frame02"			0.3)
			("cut_part" args "wood_frame03"		"wood_frame03"			0.3)
			("cut_part" args "wood_frame04"		"wood_frame04"			0.3)
			("cut_part" args "wood_frame05"		"wood_frame05"			0.3)
			("cut_part" args "wood_frame06"		"wood_frame06"			0.3)
		else min_energy 4
			(define "cut_part"
				{if rand %2
					{if volume %1
						{tear "piece_small_wood" bone %0
							{impulse up 4 2 dir 6 1}
						}
					}
				}
			)	
			("cut_part" args "wood00"		"wood00"			0.2)
			("cut_part" args "wood01"		"wood01"			0.2)
			("cut_part" args "wood02"		"wood02"			0.2)
			("cut_part" args "wood03"		"wood03"			0.2)
			("cut_part" args "wood04"		"wood04"			0.2)
			("cut_part" args "wood05"		"wood05"			0.2)
			("cut_part" args "wood06"		"wood06"			0.2)
			("cut_part" args "wood07"		"wood07"			0.2)
			("cut_part" args "wood08"		"wood08"			0.2)
			("cut_part" args "wood_frame00"		"wood_frame00"			0.1)
			("cut_part" args "wood_frame01"		"wood_frame01"			0.1)
			("cut_part" args "wood_frame02"		"wood_frame02"			0.1)
			("cut_part" args "wood_frame03"		"wood_frame03"			0.1)
			("cut_part" args "wood_frame04"		"wood_frame04"			0.1)
			("cut_part" args "wood_frame05"		"wood_frame05"			0.1)
			("cut_part" args "wood_frame06"		"wood_frame06"			0.1)
		else min_energy 12
			(define "cut_part"
				{tear "piece_small_wood" bone %0
					{impulse up 5 3 dir 5 2 cx 5 2 cy 5 2 rnd_dir 10 no_position}
				}
			)
			("cut_part" args "wood00"		"wood00"			)
			("cut_part" args "wood01"		"wood01"			)
			("cut_part" args "wood02"		"wood02"			)
			("cut_part" args "wood03"		"wood03"			)
			("cut_part" args "wood04"		"wood04"			)
			("cut_part" args "wood05"		"wood05"			)
			("cut_part" args "wood06"		"wood06"			)
			("cut_part" args "wood07"		"wood07"			)
			("cut_part" args "wood08"		"wood08"			)
			("cut_part" args "wood_frame00"		"wood_frame00"			)
			("cut_part" args "wood_frame01"		"wood_frame01"			)
			("cut_part" args "wood_frame02"		"wood_frame02"			)
			("cut_part" args "wood_frame03"		"wood_frame03"			)
			("cut_part" args "wood_frame04"		"wood_frame04"			)
			("cut_part" args "wood_frame05"		"wood_frame05"			)
			("cut_part" args "wood_frame06"		"wood_frame06"			)
		}
	}
	{on contact 
		{if effector "fraction" 
			{if contact_velocity 5
				{with_effector
					{delete}
				}
				{impulse up 0.5 dir 0.5}
				{start_sound "crush/small/wood/"}
				(define "cut_part"
					{if rand %2
						{if volume %1
							{tear "piece_small_wood" bone %0
								{impulse up 2 1 dir 2 1}
							}
						}
					}
				)	
				("cut_part" args "wood00"		"wood00"			0.4)
				("cut_part" args "wood01"		"wood01"			0.4)
				("cut_part" args "wood02"		"wood02"			0.4)
				("cut_part" args "wood03"		"wood03"			0.4)
				("cut_part" args "wood04"		"wood04"			0.4)
				("cut_part" args "wood05"		"wood05"			0.4)
				("cut_part" args "wood06"		"wood06"			0.4)
				("cut_part" args "wood07"		"wood07"			0.4)
				("cut_part" args "wood08"		"wood08"			0.4)
				("cut_part" args "wood_frame00"		"wood_frame00"			0.3)
				("cut_part" args "wood_frame01"		"wood_frame01"			0.3)
				("cut_part" args "wood_frame02"		"wood_frame02"			0.3)
				("cut_part" args "wood_frame03"		"wood_frame03"			0.3)
				("cut_part" args "wood_frame04"		"wood_frame04"			0.3)
				("cut_part" args "wood_frame05"		"wood_frame05"			0.3)
				("cut_part" args "wood_frame06"		"wood_frame06"			0.3)
			}
		else effector "tank" 
			(define "cut_part"
				{if volume %1
					{tear "piece_small_wood" bone %0
						{impulse up 5 1 dir 2 1}
					}
				}
			)	
			("cut_part" args "wood00"		"wood00"			)
			("cut_part" args "wood01"		"wood01"			)
			("cut_part" args "wood02"		"wood02"			)
			("cut_part" args "wood03"		"wood03"			)
			("cut_part" args "wood04"		"wood04"			)
			("cut_part" args "wood05"		"wood05"			)
			("cut_part" args "wood06"		"wood06"			)
			("cut_part" args "wood07"		"wood07"			)
			("cut_part" args "wood08"		"wood08"			)
			("cut_part" args "wood_frame00"		"wood_frame00"			)
			("cut_part" args "wood_frame01"		"wood_frame01"			)
			("cut_part" args "wood_frame02"		"wood_frame02"			)
			("cut_part" args "wood_frame03"		"wood_frame03"			)
			("cut_part" args "wood_frame04"		"wood_frame04"			)
			("cut_part" args "wood_frame05"		"wood_frame05"			)
			("cut_part" args "wood_frame06"		"wood_frame06"			)
		else effector "vehicle" 
			{if contact_velocity 25
				(define "cut_part"
					{if volume %1
						{tear "piece_small_wood" bone %0
							{impulse up 12 1 dir 6 1}
						}
					}
				)	
				("cut_part" args "wood00"		"wood00"			)
				("cut_part" args "wood01"		"wood01"			)
				("cut_part" args "wood02"		"wood02"			)
				("cut_part" args "wood03"		"wood03"			)
				("cut_part" args "wood04"		"wood04"			)
				("cut_part" args "wood05"		"wood05"			)
				("cut_part" args "wood06"		"wood06"			)
				("cut_part" args "wood07"		"wood07"			)
				("cut_part" args "wood08"		"wood08"			)
				("cut_part" args "wood_frame00"		"wood_frame00"			)
				("cut_part" args "wood_frame01"		"wood_frame01"			)
				("cut_part" args "wood_frame02"		"wood_frame02"			)
				("cut_part" args "wood_frame03"		"wood_frame03"			)
				("cut_part" args "wood_frame04"		"wood_frame04"			)
				("cut_part" args "wood_frame05"		"wood_frame05"			)
				("cut_part" args "wood_frame06"		"wood_frame06"			)
			else contact_velocity 15
				(define "cut_part"
					{if rand %2
						{if volume %1
							{tear "piece_small_wood" bone %0
								{impulse up 2 1 dir 2 1}
							}
						}
					}
				)	
				("cut_part" args "wood00"		"wood00"			0.7)
				("cut_part" args "wood01"		"wood01"			0.7)
				("cut_part" args "wood02"		"wood02"			0.7)
				("cut_part" args "wood03"		"wood03"			0.7)
				("cut_part" args "wood04"		"wood04"			0.7)
				("cut_part" args "wood05"		"wood05"			0.7)
				("cut_part" args "wood06"		"wood06"			0.7)
				("cut_part" args "wood07"		"wood07"			0.7)
				("cut_part" args "wood08"		"wood08"			0.7)
				("cut_part" args "wood_frame00"		"wood_frame00"			0.5)
				("cut_part" args "wood_frame01"		"wood_frame01"			0.5)
				("cut_part" args "wood_frame02"		"wood_frame02"			0.5)
				("cut_part" args "wood_frame03"		"wood_frame03"			0.5)
				("cut_part" args "wood_frame04"		"wood_frame04"			0.5)
				("cut_part" args "wood_frame05"		"wood_frame05"			0.5)
				("cut_part" args "wood_frame06"		"wood_frame06"			0.5)
			else contact_velocity 5
				(define "cut_part"
					{if rand %2
						{if volume %1
							{tear "piece_small_wood" bone %0
								{impulse up 2 1 dir 2 1}
							}
						}
					}
				)	
				("cut_part" args "wood00"		"wood00"			0.4)
				("cut_part" args "wood01"		"wood01"			0.4)
				("cut_part" args "wood02"		"wood02"			0.4)
				("cut_part" args "wood03"		"wood03"			0.4)
				("cut_part" args "wood04"		"wood04"			0.4)
				("cut_part" args "wood05"		"wood05"			0.4)
				("cut_part" args "wood06"		"wood06"			0.4)
				("cut_part" args "wood07"		"wood07"			0.4)
				("cut_part" args "wood08"		"wood08"			0.4)
				("cut_part" args "wood_frame00"		"wood_frame00"			0.3)
				("cut_part" args "wood_frame01"		"wood_frame01"			0.3)
				("cut_part" args "wood_frame02"		"wood_frame02"			0.3)
				("cut_part" args "wood_frame03"		"wood_frame03"			0.3)
				("cut_part" args "wood_frame04"		"wood_frame04"			0.3)
				("cut_part" args "wood_frame05"		"wood_frame05"			0.3)
				("cut_part" args "wood_frame06"		"wood_frame06"			0.3)
			}
		}
	}
}


{"wood_build_new"
	{on "burn_volume"
		{if not "burned"
			{set "burned" 1}
			{if volume "fire"
				{call "_burns"}
			}
		}
	}
	{on "_burns"
		{fire radius 0.3 time 40 heating 3}
		{burn volume fx "smoke_dead_norm" time 37 fake even_law}
		{burn volume fx "smoke_camp_storeable" time 54 fake even_law}
		{delay 8 2 "burn_die1"
			{tex_morph "d" 5}
			{call "_burn_crash"}
			{delay 6 "_burn_crash_end"
				{call "_burn_crash_end"}
			}
			{delay 12 3 "burn_die2"
				{call "_burn_crash"}
				{delay 16 2 "burn_die3"
					{tex_morph "b" 12}
					{call "_burn_crash"}
				}
			}
		}
	}
	{on "_burn_crash"
		{start_sound "crush/small/wood/"}
		(define "_burn_crash"
			{if rand %1
				{tear "piece_small_wood" bone %0
					{impulse up 0.3 dir 0.3}
				}
			}
		)	
		("_burn_crash" args "plank00"			0.2)
		("_burn_crash" args "plank01"			0.2)
		("_burn_crash" args "plank02"			0.2)
		("_burn_crash" args "plank03"			0.2)
		("_burn_crash" args "plank04"			0.2)
		("_burn_crash" args "plank05"			0.2)
		("_burn_crash" args "plank06"			0.2)
		("_burn_crash" args "plank07"			0.2)
		("_burn_crash" args "plank08"			0.2)
		("_burn_crash" args "plank09"			0.2)
		("_burn_crash" args "plank10"			0.2)
		("_burn_crash" args "plank11"			0.2)
		("_burn_crash" args "plank12"			0.2)
		("_burn_crash" args "plank13"			0.2)
		("_burn_crash" args "plank14"			0.2)
		("_burn_crash" args "plank15"			0.2)
		("_burn_crash" args "plank16"			0.2)
		("_burn_crash" args "plank17"			0.2)
		("_burn_crash" args "plank18"			0.2)
		("_burn_crash" args "plank19"			0.2)
		("_burn_crash" args "plank20"			0.2)
		("_burn_crash" args "plank21"			0.2)
		("_burn_crash" args "plank22"			0.2)
		("_burn_crash" args "plank23"			0.2)
		("_burn_crash" args "plank24"			0.2)
		("_burn_crash" args "plank25"			0.2)
		("_burn_crash" args "plank26"			0.2)
		("_burn_crash" args "plank27"			0.2)
		("_burn_crash" args "plank28"			0.2)
		("_burn_crash" args "plank29"			0.2)
		("_burn_crash" args "plank30"			0.2)
	}
	{on "_burn_crash_end"
		{delay 18
			{start_sound "crush/small/wood/"}
			(define "_burn_crash"
				{if rand %1
					{tear "piece_small_wood" bone %0
						{impulse up 0.3 dir 0.3}
					}
				}
			)	
			("_burn_crash" args "plank00"			0.2)
			("_burn_crash" args "plank01"			0.2)
			("_burn_crash" args "plank02"			0.2)
			("_burn_crash" args "plank03"			0.2)
			("_burn_crash" args "plank04"			0.2)
			("_burn_crash" args "plank05"			0.2)
			("_burn_crash" args "plank06"			0.2)
			("_burn_crash" args "plank07"			0.2)
			("_burn_crash" args "plank08"			0.2)
			("_burn_crash" args "plank09"			0.2)
			("_burn_crash" args "plank10"			0.2)
			("_burn_crash" args "plank11"			0.2)
			("_burn_crash" args "plank12"			0.2)
			("_burn_crash" args "plank13"			0.2)
			("_burn_crash" args "plank14"			0.2)
			("_burn_crash" args "plank15"			0.2)
			("_burn_crash" args "plank16"			0.2)
			("_burn_crash" args "plank17"			0.2)
			("_burn_crash" args "plank18"			0.2)
			("_burn_crash" args "plank19"			0.2)
			("_burn_crash" args "plank20"			0.2)
			("_burn_crash" args "plank21"			0.2)
			("_burn_crash" args "plank22"			0.2)
			("_burn_crash" args "plank23"			0.2)
			("_burn_crash" args "plank24"			0.2)
			("_burn_crash" args "plank25"			0.2)
			("_burn_crash" args "plank26"			0.2)
			("_burn_crash" args "plank27"			0.2)
			("_burn_crash" args "plank28"			0.2)
			("_burn_crash" args "plank29"			0.2)
			("_burn_crash" args "plank30"			0.2)
		}
	}
	{on bullet_hit 
		{if stuff "fx_40"
			{tear "piece_small_wood" bone from_volume
				{impulse up 6 2.5 dir 5 1 cx 7 3.5 cy 7 3.5 rnd_dir 5 no_position}
			}
			{bullet_detonate}	
		}
		(define "anim_part_new"
			{if volume %0
				{if rand %1
					{if not tagged "broken_%2"	
						{tags add "broken_%2"}
						{ani_play "%2" 0.8 }
					}
				}
			}
		)	
		("anim_part_new" args "plank08" 0.8 plank08)
		("anim_part_new" args "plank10" 0.8 plank10)
		("anim_part_new" args "plank13" 0.8 plank13)
		("anim_part_new" args "plank14" 0.8 plank14)
		("anim_part_new" args "plank17" 0.8 plank17)
		("anim_part_new" args "plank18" 0.8 plank18)
		("anim_part_new" args "plank24" 0.8 plank24)
		("anim_part_new" args "plank25" 0.8 plank25)
		("anim_part_new" args "plank29" 0.8 plank29)
		("anim_part_new" args "plank30" 0.8 plank30)
		("anim_part_new" args "plank01" 0.8 plank01)
	}
	{on pierce sync
		{if volume "rail00"
			(define "cut_part"
				{if rand %1
					{tear "piece_small_wood" bone %0
						{impulse up 2 1 dir 1 0.5}
					}
				}
			)	
			("cut_part" args "plank15"			0.2)
			("cut_part" args "plank16"			0.2)
			("cut_part" args "plank19"			0.2)
			("cut_part" args "plank20"			0.2)
			("cut_part" args "plank21"			0.2)
			("cut_part" args "plank22"			0.2)
			("cut_part" args "plank23"			0.2)
			("cut_part" args "plank26"			0.2)
			("cut_part" args "plank29"			0.2)
			("cut_part" args "plank30"			0.2)
			("cut_part" args "rail00"			0.01)
		else volume "rail01"
			(define "cut_part"
				{if rand %1
					{tear "piece_small_wood" bone %0
						{impulse up 2 1 dir 1 0.5}
					}
				}
			)	
			("cut_part" args "plank00"			0.2)
			("cut_part" args "plank01"			0.2)
			("cut_part" args "plank02"			0.2)
			("cut_part" args "plank04"			0.2)
			("cut_part" args "plank05"			0.2)
			("cut_part" args "plank06"			0.2)
			("cut_part" args "plank08"			0.2)
			("cut_part" args "plank10"			0.2)
			("cut_part" args "plank11"			0.2)
			("cut_part" args "plank13"			0.2)
			("cut_part" args "plank14"			0.2)
			("cut_part" args "rail01"			0.01)
		else volume "rail02"
			(define "cut_part"
				{if rand %1
					{tear "piece_small_wood" bone %0
						{impulse up 2 1 dir 1 0.5}
					}
				}
			)	
			("cut_part" args "plank00"			0.2)
			("cut_part" args "plank01"			0.2)
			("cut_part" args "plank02"			0.2)
			("cut_part" args "plank04"			0.2)
			("cut_part" args "plank13"			0.2)
			("cut_part" args "rail02"			0.01)
		else volume "parts"
			{if stuff "shell"
				{start_sound "crush/small/wood/"}
				{tear "piece_small_wood" bone from_volume
					{impulse up 5 1 dir 7 2 cx 3 2 cy 3 2 rnd_dir 7 no_position}
				}
			else stuff "shell_minimum"
				{start_sound "crush/small/wood/"}
				{tear "piece_small_wood" bone from_volume
					{impulse up 2 1 dir 7 2 cx 3 2 cy 3 2 rnd_dir 7 no_position}
				}
			else stuff "fx_40"
				{if rand 0.8
					{start_sound "crush/small/wood/"}
					{tear "piece_small_wood" bone from_volume
						{impulse up 2 1 dir 7 2 cx 3 2 cy 3 2 rnd_dir 7 no_position}
					}
				}
			else stuff "bullet ap"
				{if rand 0.7
					{start_sound "crush/small/wood/"}
					{tear "piece_small_wood" bone from_volume
						{impulse up 2 1 dir 2 1 cx 2 1 cy 2 1 rnd_dir 2 no_position}
					}
				}
			else stuff "bullet"
				{if rand 0.4
					{start_sound "crush/small/wood/"}
					{tear "piece_small_wood" bone from_volume
						{impulse up 1 0.5 dir 2 1 cx 1 0.5 cy 1 0.5 rnd_dir 1 no_position}
					}
				}
			}
		}
	}
	{on blast
		{if min_energy 12
			(define "cut_min_energy_12"
				{if volume %0
					{start_sound "crush/small/wood/"}
					{tear "piece_small_wood" bone %0
						{impulse up 7 3 dir 7 2 cx 5 3 cy 5 3 rnd_dir 7 no_position}
					}
				}
			)
			("cut_min_energy_12" args "plank00"			0.5)
			("cut_min_energy_12" args "plank01"			0.5)
			("cut_min_energy_12" args "plank02"			0.5)
			("cut_min_energy_12" args "plank03"			0.5)
			("cut_min_energy_12" args "plank04"			0.5)
			("cut_min_energy_12" args "plank05"			0.5)
			("cut_min_energy_12" args "plank06"			0.5)
			("cut_min_energy_12" args "plank07"			0.5)
			("cut_min_energy_12" args "plank08"			0.5)
			("cut_min_energy_12" args "plank09"			0.5)
			("cut_min_energy_12" args "plank10"			0.5)
			("cut_min_energy_12" args "plank11"			0.5)
			("cut_min_energy_12" args "plank12"			0.5)
			("cut_min_energy_12" args "plank13"			0.5)
			("cut_min_energy_12" args "plank14"			0.5)
			("cut_min_energy_12" args "plank15"			0.5)
			("cut_min_energy_12" args "plank16"			0.5)
			("cut_min_energy_12" args "plank17"			0.5)
			("cut_min_energy_12" args "plank18"			0.5)
			("cut_min_energy_12" args "plank19"			0.5)
			("cut_min_energy_12" args "plank20"			0.5)
			("cut_min_energy_12" args "plank21"			0.5)
			("cut_min_energy_12" args "plank22"			0.5)
			("cut_min_energy_12" args "plank23"			0.5)
			("cut_min_energy_12" args "plank24"			0.5)
			("cut_min_energy_12" args "plank25"			0.5)
			("cut_min_energy_12" args "plank26"			0.5)
			("cut_min_energy_12" args "plank27"			0.5)
			("cut_min_energy_12" args "plank28"			0.5)
			("cut_min_energy_12" args "plank29"			0.5)
			("cut_min_energy_12" args "plank30"			0.5)
			("cut_min_energy_12" args "rail00"			0.5)
			("cut_min_energy_12" args "rail01"			0.5)
			("cut_min_energy_12" args "rail02"			0.5)
		else min_energy 7
			(define "cut_min_energy_7"
				{if volume %0
					{tear "piece_small_wood" bone %0
						{impulse up 7 3 dir 7 2 cx 5 2 cy 5 2 rnd_dir 7 no_position}
					}
				}
			)
			("cut_min_energy_7" args "plank00"			0.4)
			("cut_min_energy_7" args "plank01"			0.4)
			("cut_min_energy_7" args "plank02"			0.4)
			("cut_min_energy_7" args "plank03"			0.4)
			("cut_min_energy_7" args "plank04"			0.4)
			("cut_min_energy_7" args "plank05"			0.4)
			("cut_min_energy_7" args "plank06"			0.4)
			("cut_min_energy_7" args "plank07"			0.4)
			("cut_min_energy_7" args "plank08"			0.4)
			("cut_min_energy_7" args "plank09"			0.4)
			("cut_min_energy_7" args "plank10"			0.4)
			("cut_min_energy_7" args "plank11"			0.4)
			("cut_min_energy_7" args "plank12"			0.4)
			("cut_min_energy_7" args "plank13"			0.4)
			("cut_min_energy_7" args "plank14"			0.4)
			("cut_min_energy_7" args "plank15"			0.4)
			("cut_min_energy_7" args "plank16"			0.4)
			("cut_min_energy_7" args "plank17"			0.4)
			("cut_min_energy_7" args "plank18"			0.4)
			("cut_min_energy_7" args "plank19"			0.4)
			("cut_min_energy_7" args "plank20"			0.4)
			("cut_min_energy_7" args "plank21"			0.4)
			("cut_min_energy_7" args "plank22"			0.4)
			("cut_min_energy_7" args "plank23"			0.4)
			("cut_min_energy_7" args "plank24"			0.4)
			("cut_min_energy_7" args "plank25"			0.4)
			("cut_min_energy_7" args "plank26"			0.4)
			("cut_min_energy_7" args "plank27"			0.4)
			("cut_min_energy_7" args "plank28"			0.4)
			("cut_min_energy_7" args "plank29"			0.4)
			("cut_min_energy_7" args "plank30"			0.4)
		else min_energy 5
			(define "cut_min_energy_5"
				{if volume %0
					{tear "piece_small_wood" bone %0
						{impulse up 4 3 dir 7 2 cx 3 2 cy 3 2 rnd_dir 7 no_position}
					}
				}
			)
			("cut_min_energy_5" args "plank00"			0.2)
			("cut_min_energy_5" args "plank01"			0.2)
			("cut_min_energy_5" args "plank02"			0.2)
			("cut_min_energy_5" args "plank03"			0.2)
			("cut_min_energy_5" args "plank04"			0.2)
			("cut_min_energy_5" args "plank05"			0.2)
			("cut_min_energy_5" args "plank06"			0.2)
			("cut_min_energy_5" args "plank07"			0.2)
			("cut_min_energy_5" args "plank08"			0.2)
			("cut_min_energy_5" args "plank09"			0.2)
			("cut_min_energy_5" args "plank10"			0.2)
			("cut_min_energy_5" args "plank11"			0.2)
			("cut_min_energy_5" args "plank12"			0.2)
			("cut_min_energy_5" args "plank13"			0.2)
			("cut_min_energy_5" args "plank14"			0.2)
			("cut_min_energy_5" args "plank15"			0.2)
			("cut_min_energy_5" args "plank16"			0.2)
			("cut_min_energy_5" args "plank17"			0.2)
			("cut_min_energy_5" args "plank18"			0.2)
			("cut_min_energy_5" args "plank19"			0.2)
			("cut_min_energy_5" args "plank20"			0.2)
			("cut_min_energy_5" args "plank21"			0.2)
			("cut_min_energy_5" args "plank22"			0.2)
			("cut_min_energy_5" args "plank23"			0.2)
			("cut_min_energy_5" args "plank24"			0.2)
			("cut_min_energy_5" args "plank25"			0.2)
			("cut_min_energy_5" args "plank26"			0.2)
			("cut_min_energy_5" args "plank27"			0.2)
			("cut_min_energy_5" args "plank28"			0.2)
			("cut_min_energy_5" args "plank29"			0.2)
			("cut_min_energy_5" args "plank30"			0.2)
		else min_energy 2
			(define "cut_min_energy_1"
				{if rand %1
					{if volume %0
						{tear "piece_small_wood" bone %0
							{impulse up 2 0.5 dir 2 1 cx 5 1 cy 5 1 rnd_dir 4 no_position}
						}
					}
				}
			)
			("cut_min_energy_1" args "plank00"			0.2)
			("cut_min_energy_1" args "plank01"			0.2)
			("cut_min_energy_1" args "plank02"			0.2)
			("cut_min_energy_1" args "plank03"			0.2)
			("cut_min_energy_1" args "plank04"			0.2)
			("cut_min_energy_1" args "plank05"			0.2)
			("cut_min_energy_1" args "plank06"			0.2)
			("cut_min_energy_1" args "plank07"			0.2)
			("cut_min_energy_1" args "plank08"			0.2)
			("cut_min_energy_1" args "plank09"			0.2)
			("cut_min_energy_1" args "plank10"			0.2)
			("cut_min_energy_1" args "plank11"			0.2)
			("cut_min_energy_1" args "plank12"			0.2)
			("cut_min_energy_1" args "plank13"			0.2)
			("cut_min_energy_1" args "plank14"			0.2)
			("cut_min_energy_1" args "plank15"			0.2)
			("cut_min_energy_1" args "plank16"			0.2)
			("cut_min_energy_1" args "plank17"			0.2)
			("cut_min_energy_1" args "plank18"			0.2)
			("cut_min_energy_1" args "plank19"			0.2)
			("cut_min_energy_1" args "plank20"			0.2)
			("cut_min_energy_1" args "plank21"			0.2)
			("cut_min_energy_1" args "plank22"			0.2)
			("cut_min_energy_1" args "plank23"			0.2)
			("cut_min_energy_1" args "plank24"			0.2)
			("cut_min_energy_1" args "plank25"			0.2)
			("cut_min_energy_1" args "plank26"			0.2)
			("cut_min_energy_1" args "plank27"			0.2)
			("cut_min_energy_1" args "plank28"			0.2)
			("cut_min_energy_1" args "plank29"			0.2)
			("cut_min_energy_1" args "plank30"			0.2)
		else min_energy 1
			(define "cut_min_energy_1"
				{if rand %1
					{if volume %0
						{tear "piece_small_wood" bone %0
							{impulse up 1 0.5 dir 2 1 cx 2 1 cy 2 1 rnd_dir 2 no_position}
						}
					}
				}
			)
			("cut_min_energy_1" args "plank00"			0.2)
			("cut_min_energy_1" args "plank01"			0.2)
			("cut_min_energy_1" args "plank02"			0.2)
			("cut_min_energy_1" args "plank03"			0.2)
			("cut_min_energy_1" args "plank04"			0.2)
			("cut_min_energy_1" args "plank05"			0.2)
			("cut_min_energy_1" args "plank06"			0.2)
			("cut_min_energy_1" args "plank07"			0.2)
			("cut_min_energy_1" args "plank08"			0.2)
			("cut_min_energy_1" args "plank09"			0.2)
			("cut_min_energy_1" args "plank10"			0.2)
			("cut_min_energy_1" args "plank11"			0.2)
			("cut_min_energy_1" args "plank12"			0.2)
			("cut_min_energy_1" args "plank13"			0.2)
			("cut_min_energy_1" args "plank14"			0.2)
			("cut_min_energy_1" args "plank15"			0.2)
			("cut_min_energy_1" args "plank16"			0.2)
			("cut_min_energy_1" args "plank17"			0.2)
			("cut_min_energy_1" args "plank18"			0.2)
			("cut_min_energy_1" args "plank19"			0.2)
			("cut_min_energy_1" args "plank20"			0.2)
			("cut_min_energy_1" args "plank21"			0.2)
			("cut_min_energy_1" args "plank22"			0.2)
			("cut_min_energy_1" args "plank23"			0.2)
			("cut_min_energy_1" args "plank24"			0.2)
			("cut_min_energy_1" args "plank25"			0.2)
			("cut_min_energy_1" args "plank26"			0.2)
			("cut_min_energy_1" args "plank27"			0.2)
			("cut_min_energy_1" args "plank28"			0.2)
			("cut_min_energy_1" args "plank29"			0.2)
			("cut_min_energy_1" args "plank30"			0.2)
		}
	}
	{on contact sync
		{if effector "fraction" 
			{if rand 0.8
				{with_effector
					{delete}
				}
				{tear "piece_small_wood" bone from_volume
					{impulse up 1.5 0.5 dir 1 0.5 cx 1 0.5 cy 1 0.5 rnd_dir 1 no_position}
				}
			}
		else effector "tank" 
			{if contact_velocity 3
				{tear "piece_small_wood" bone from_volume
					{impulse up 1 0.5 dir 2 1 cx 1 0.5 cy 1 0.5 rnd_dir 1 no_position}
				}
			}
		else effector "vehicle" 
			{if contact_velocity 25
				{tear "piece_small_wood" bone from_volume
					{impulse up 5 1 dir 7 2 cx 7 5 cy 7 5 rnd_dir 7 no_position}
				}
			else contact_velocity 15
				{tear "piece_small_wood" bone from_volume
					{impulse up 2 1 dir 3 2 cx 2 1.5 cy 2 1.5 rnd_dir 2 no_position}
				}
			else contact_velocity 5
				{if rand 0.6
					{tear "piece_small_wood" bone from_volume
						{impulse up 1 0.5 dir 2 1}
					}
				}
			}
		}
	}
}

{"oilpipe parts construction"
	{inflammation_time 20}
	{on spawn
		{set "exploded" 0}
	}
	{on break_armor
		{if name "pierce"
			{if stuff "bullet"
				{burn fx "drops_water_small_short" fake}
			else stuff "shell"
				{call "break"}
			}
		else name "blast"
			{call "break"}
		}
	}
	{on "burn"
		{call "break"}
	}
	{on "break"
		{call "explosion"}
	}
	{on "explosion"
		{if not "exploded"
			{set "exploded" 1}
			{blastwave c4 5 r0 1 r1 2}
			{fire radius 1.5 time 6 heating 0.2}
			{spawn "aero_die_fire" "root" offset 0 0 7}
			{spawn "fire_mark_1" "root"}
		}
	}
}

