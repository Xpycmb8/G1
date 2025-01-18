
{"part"
	{on "check_delete_part" ; called only inside tear, so with_effector swaps entity&effector for flag check
		{with_effector
			{if "delete_parts"
				{with_effector
					{delay 20
						{hide 3}
					}
				}
			}
		}
	}
}

{"flesh"
	{on blast  {spawn "bloodsparks_small"}}
	{on bullet_hit {spawn "bloodsparks_small"}}
	{on contact
		;{spawn "bloodsparks_small"}
	}
	{on ground_hit
		{if min_speed 10
			{spawn "bloodsparks_small"}
		}
	}
}

{"small part"
	{on spawn
		(define "visible"
			{if bone "%0" visible
				{bone hide "%0"}
			}	
		)
		("visible" 	visible(glass_f_s_l_add))
		("visible" 	visible(glass_f_s_r_add))
		("visible" 	visible(glass_f_m_l_add))
		("visible" 	visible(glass_f_m_r_add))
		{delay 0.1
			{volumes disable bullet contact blast touch}	;prevent destroing at spawn moment
		}
		{delay 0.5 {volumes enable bullet contact blast}}
		{call "stop_view"}
		{delay 90 {hide 10}}
	}
	{on blast_hit
;		{con "blast small part"}
;		{if min_energy 0.5
;			{hide 1}
;		else
			{impulse up 3 1 dir 2 1}
;		}
	}
	{on bullet_hit
		(define "impact"
			{if stuff "%stuff"
				%impact	
			}	
		)
		("impact" 	stuff(shell_big) 					impact({impulse up 4 2 		dir 5 2 		cx 7 2 cy 7 2 rnd_dir 5 no_position}))
		("impact" 	stuff(atgm_launcher) 				impact({impulse up 4 2 		dir 20 10 		cx 7 2 cy 7 2 rnd_dir 5 no_position}))
		("impact" 	stuff(shell_minimum)				impact({impulse up 3 2 		dir 12 7 		cx 7 2 cy 7 2 rnd_dir 5 no_position}))         
		("impact" 	stuff(rocketlauncher shell)  	 	impact({impulse up 4 2 		dir 5 2 		cx 7 2 cy 7 2 rnd_dir 5 no_position}))         
		("impact" 	stuff(grenade fg)  					impact({impulse up 3 2 		dir 5 2 		cx 7 2 cy 7 2 rnd_dir 5 no_position}))         
		("impact" 	stuff(zenite th)  					impact({impulse up 1 0.5 	dir 2 1 		cx 3 1 cy 3 1 rnd_dir 2 no_position}))         
		("impact" 	stuff(zenite fg)  					impact({impulse up 2 1 		dir 4 1 		cx 3 1 cy 3 1 rnd_dir 2 no_position}))         
		("impact" 	stuff(zenite ap)  					impact({impulse up 1 0.5 	dir 2 1 		cx 3 1 cy 3 1 rnd_dir 2 no_position}))         
		("impact" 	stuff(bullet sp big)  				impact({impulse up 1 0.5 	dir 2 1 		cx 2 1 cy 2 1 rnd_dir 1 no_position}))  
		("impact" 	stuff(bullet ap big)  				impact({impulse up 2 0.5 	dir 3 2 		cx 4 2 cy 4 2 rnd_dir 4 no_position}))  
		("impact" 	stuff(bullet fg big)  				impact({impulse up 3 2 		dir 3 2 		cx 4 2 cy 4 2 rnd_dir 4 no_position}))   
		("impact" 	stuff(bullet small)  		 		impact({impulse up 1 0.5 	dir 2 1 		cx 3 1 cy 3 1 rnd_dir 2 no_position}))    
		("impact" 	stuff(bullet normal)  		 		impact({impulse up 2 0.5 	dir 3 1 		cx 3 1 cy 3 1 rnd_dir 2 no_position}))      
	}
	{on contact
;		{con "contact small part"}
;		{if effector "vehicle"
;			{volumes disable bullet contact blast}	;prevent destroing at spawn moment
;			{hide 1}
;		}
	}
}
{"small part wood"
	{inflammation_time 1}
	{on "burn_volume"
		{if not "burned"
			{set "burned" 1}
			{burn volume fx "smoke_wood_small_fire" time 10 fake even_law}	
			{fire radius 0.3 heating 2  time 10 follow}
			{tex_morph "burned" 1}
		}
	}
}

{"plastic"
	{on blast_hit
		{if min_energy 1
			{spawn "plastic_crush_big"}
			{delete}
		else
			{impulse dir 2 1 up 2 1 dir 7 2 cx 0 0.5 cy 0 0.5}
		}
	}
	{on bullet_hit
		{if stuff "shell"
			{spawn "plastic_crush_big"}
			{delete}
		else stuff "bullet zenite"
			{spawn "plastic_crush_big"}
			{delete}
		else stuff "bullet big"
			{impulse dir 6 1 up 2 1 cx 1 0.5 cy 1 0.5}
		else stuff "bullet"
			{if rand 0.1
				{spawn "plastic_crush_big"}
				{delete}
			}
			{impulse dir 2 1 up 2 1 cx 0 0.5 cy 0 0.5}
		}
	}
}

{"small part fx"
	{on "stop_view"
		{delay 0.5 0.3 {view stop ""}}
	}
}

{"medium part"
;	{friction 2}
;	{restitution 0.2}
	{on spawn
		{delay 0.1
			{volumes disable bullet contact blast touch}	;prevent destroing at spawn moment
		}
		{delay 1 {volumes enable bullet contact blast}}
		(define "visible"
			{if bone "%0" visible
				{bone hide "%0"}
			}	
		)
		("visible" 	visible(glass_f_s_l_add))
		("visible" 	visible(glass_f_s_r_add))
		("visible" 	visible(glass_f_m_l_add))
		("visible" 	visible(glass_f_m_r_add))
	}
	{on bullet_hit
		(define "impact"
			{if stuff "%stuff"
				%impact	
			}	
		)
		("impact" 	stuff(shell_big) 					impact({impulse up 4 2 		dir 5 2 		cx 7 2 cy 7 2 rnd_dir 5 no_position}))
		("impact" 	stuff(atgm) 						impact({impulse up 4 2 		dir 20 10 		cx 7 2 cy 7 2 rnd_dir 5 no_position}))
		("impact" 	stuff(shell_minimum)				impact({impulse up 3 2 		dir 12 7 		cx 7 2 cy 7 2 rnd_dir 5 no_position}))         
		("impact" 	stuff(rocketlauncher shell)  	 	impact({impulse up 4 2 		dir 5 2 		cx 7 2 cy 7 2 rnd_dir 5 no_position}))         
		("impact" 	stuff(grenade fg)  					impact({impulse up 3 2 		dir 5 2 		cx 7 2 cy 7 2 rnd_dir 5 no_position}))         
		("impact" 	stuff(zenite th)  					impact({impulse up 1 0.5 	dir 2 1 		cx 3 1 cy 3 1 rnd_dir 2 no_position}))         
		("impact" 	stuff(zenite fg)  					impact({impulse up 2 1 		dir 4 1 		cx 3 1 cy 3 1 rnd_dir 2 no_position}))         
		("impact" 	stuff(zenite ap)  					impact({impulse up 1 0.5 	dir 2 1 		cx 3 1 cy 3 1 rnd_dir 2 no_position}))         
		("impact" 	stuff(bullet sp big)  				impact({impulse up 1 0.5 	dir 2 1 		cx 2 1 cy 2 1 rnd_dir 1 no_position}))  
		("impact" 	stuff(bullet ap big)  				impact({impulse up 2 0.5 	dir 3 2 		cx 4 2 cy 4 2 rnd_dir 4 no_position}))  
		("impact" 	stuff(bullet fg big)  				impact({impulse up 3 2 		dir 3 2 		cx 4 2 cy 4 2 rnd_dir 4 no_position}))   
		("impact" 	stuff(bullet small)  		 			impact({impulse up 1 0.5 	dir 2 1 		cx 3 1 cy 3 1 rnd_dir 2 no_position}))    
		("impact" 	stuff(bullet normal)  		 			impact({impulse up 2 0.5 	dir 3 1 		cx 3 1 cy 3 1 rnd_dir 2 no_position}))      
	}
	{on contact
		{impulse up 0.1 0.1 dir 0.1 0.1}
	}
}

{"big part"
;	{friction 2}
;	{restitution 0.1}
	{on spawn
		{delay 0.1
			{volumes disable touch}
		}
		(define "visible"
			{if bone "%0" visible
				{bone hide "%0"}
			}	
		)
		("visible" 	visible(glass_f_s_l_add))
		("visible" 	visible(glass_f_s_r_add))
		("visible" 	visible(glass_f_m_l_add))
		("visible" 	visible(glass_f_m_r_add))
	}
	{on bullet_hit
		{if stuff "big shell extra"
			{impulse up 5 1 dir 5 1}
		 else stuff "shell"
			{impulse up 1 0.3 dir 1 0.5}
		 else stuff "zenite"
			{impulse up 0.2 0.1 dir 0.1 0.05}
		}
	}
}

{"big part delete"
	{on spawn
		{delay 20
			{delete}
		}
	}
}

{"wood part"
	{on spawn
		{delay 2
			{volumes enable float}
		}
	}
;	{on ground_hit
;		{if terrain "water"
;			{call "kick"}
;		else terrain "deep_water"
;			{call "kick"}
;		}
;	}
;	{on "kick"
;		{delay 15
;			{kill_delay "kick_process"}
;		}
;		{call "kick_process"}
;	}
;	{on "kick_process"
;		{delay 0.3 0.1 "kick_process"
;			{impulse up 1}
;			{call "kick_process"}
;		}
;	}
}


{"forward_tear"
	{on spawn
		{impulse forward 2 1 dir 5 2 cx 4 2}
		{burn volume fx "smoke_destroy" time 3 1 fake}			
		{delay 0
			{volumes disable contact blast }	;prevent destroing at spawn moment
		}
		{delay 1 {volumes enable contact blast}}
	}
}

