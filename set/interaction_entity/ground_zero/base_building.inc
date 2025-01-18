{"base_building"
	(define "list" ;         0														1 													2
		("stack" args building_resistance_wall_01_metal_fence 				building_resistance_wall_01_metal_fence_vis 				select_1)
		("stack" args building_resistance_wall_01_metal_fence_corner 		building_resistance_wall_01_metal_fence_corner_vis			select_2)
		("stack" args buildings_resistance_sandbag_shooting_position_nest 	buildings_resistance_sandbag_shooting_position_nest_vis 	select_3)
		("stack" args resistance_buildings_01_wall_scaffolds 				resistance_buildings_01_wall_scaffolds_vis 					select_4)
		("stack" args resistance_buildings_01_wall_ramp 					resistance_buildings_01_wall_ramp_vis 						select_5)	
		("stack" args building_soviet_barrier_01_cover 						building_soviet_barrier_01_cover_vis 						select_6)		
		("stack" args building_soviet_barrier_pylon_01_corner 				building_soviet_barrier_pylon_01_corner_vis 				select_7)
		;("stack" args  select_8)
		;("stack" args  select_9)
	)
	{on spawn
		{add_view 	"move_build" 		"move_build" 			"basis"}		
		(define "stack"
			{add_view 	"%1" 				"%2" 			"basis"}
			{view hide "%2"}
		)
		("list")
	}
	{on animation_event "clear"
		(define "stack"
			{view hide "select_1"}			
			{view hide "select_2"}			
			{view hide "select_3"}			
			{view hide "select_4"}			
			{view hide "select_5"}			
			{view hide "select_6"}			
			{view hide "select_7"}			
			{view hide "select_8"}			
			{view hide "select_9"}			
			{tags remove "%0"}
		)
		("stack" args select_1)
		("stack" args select_2)
		("stack" args select_3)
		("stack" args select_4)
		("stack" args select_5)
		("stack" args select_6)
		("stack" args select_7)
	}		
	{on "instal"
		{start_sound "generation_zero/base_defence/install/"}							
		(define "stack"
			{if tagged "%2"
				{spawn "%0" "basis" x {tags add "build"}}
				{delete}
			}
		)
		("list")
	}
	(define "stack"
		{on animation_event "%2"
			{tags add "%2"}
			{view show "%2"}			
			{ani_stop "select" }
		}		
	)
	("list")
	{on "select_next"
		{ani_play "select" +0.3 resume}
	}
	{on "select_prev"
		{ani_play "select" -0.3 resume}
	}
	{on "hide_all"
		{if tagged "hide"
			{tags remove "hide"}
			{bone show "link"}
		else
			{tags add "hide"}
			{bone hide "link"}
		}
	}
	{on "left_rotate"
		{volumes "rotate" disable touch }	
		{ani_play "rot45_1" -2 callback }
	}
	{on "right_rotate"
		{volumes "rotate" disable touch }	
		{ani_play "rot45_1" 2 callback }
	}
	{on animation_end "rot45_1"
		{pillar_up}
		{volumes "rotate" enable touch }	
	}
	{on "mode"
		{start_sound "generation_zero/base_defence/mode/"}									
		{volumes "mode" disable touch }	
		{ani_play "mode" 1 resume callback}
	}
	{on animation_event "manual"
		{if not tagged "reset"
			{volumes "mode" enable touch }	
			{ani_stop "mode" }
			{bone show "manual"}			
			{bone show "stop"}
			{bone hide "auto"}
			{tags add "manual"}
			{tags remove "auto"}
			{tags remove "manual_2"}
		}
	}
	{on animation_event "manual_2"
		{if not tagged "reset"
			{volumes "mode" enable touch }	
			{ani_stop "mode" }
			{bone show "manual_2"}			
			{bone show "stop"}
			{bone hide "manual"}
			{bone hide "auto"}
			{tags add "manual_2"}
			{tags remove "manual"}
			{tags remove "auto"}
		}
	}
	{on animation_event "auto"
		{if not tagged "reset"
			{volumes "mode" enable touch }	
			{tags add "reset"}
			{ani_play "mode" -10 }
			{bone show "auto"}			
			{bone hide "stop"}
			{bone hide "manual"}
			{bone hide "manual_2"}
			{tags remove "manual_2"}
			{tags remove "manual"}
			{tags add "auto"}
			{delay 0.2
				{tags remove "reset"}
			}
		}
	}
	{on "manual_stop"
		{if not tagged "auto"
			{start_sound "generation_zero/base_defence/stop/"}									
			{volumes "stop" disable touch }	
			(define "move"
				{if tagged "%0"
					{ani_stop "%0"  }
					{bone hide "%0_start"}
					{view pause "move_build"}
					{bone show "%0"}
					{delay 0.4
						{view pause "move_build"}
					}
				}
			)
			("move" args right )
			("move" args left )
			("move" args front )
			("move" args back )
			{delay 0.5
				{volumes "stop" enable touch }	
			}
		}
	}
	(define "move"
		{on "%0"
			{if tagged "manual"
				{call "hide_all"}
				{tags add "%0"}
				{volumes "move" disable touch }	
				{ani_play "%0" 0.5 callback }
				{start_sound "generation_zero/base_defence/move/"}							
				{bone show "%0_start"}
				{delay 1.5
					{bone hide "%0_start"}
				}
			else tagged "manual_2"
				{call "hide_all"}
				{tags add "%0"}
				{volumes "move" disable touch }	
				{ani_play "%0" 0.05 callback }
				{start_sound "generation_zero/base_defence/move/"}							
				{bone show "%0_start"}
				{delay 1
					;{ani_stop "%0" }
					;{tags remove "%0"}
					{pillar_up}
					{volumes "move" enable touch }	
					{bone hide "%0_start"}
				}
			else
				{call "hide_all"}
				{tags add "%0"}
				{volumes "move" disable touch }	
				{ani_play "%0" 5 callback }
				{start_sound "generation_zero/base_defence/move/"}							
				{view start "move_build"}
				{bone show "%0_start"}
				{delay 0.4
					{view pause "move_build"}
					{bone hide "%0_start"}
				}
			}
		}
		{on animation_end "%0"
			{call "hide_all"}
			{tags remove "%0"}
			{pillar_up}
			{volumes "move" enable touch }	
		}
	)
	("move" args right )
	("move" args left )
	("move" args front )
	("move" args back )
	{on animation_event "right"
		{bone hide "left"}		
		{bone hide "front"}		
		{bone hide "back"}		
		{delay 1
			{bone show "left"}		
			{bone show "front"}		
			{bone show "back"}		
		}
	}
	{on animation_event "left"
		{bone hide "right"}		
		{bone hide "front"}		
		{bone hide "back"}		
		{delay 1
			{bone show "right"}		
			{bone show "front"}		
			{bone show "back"}		
		}
	}
	{on animation_event "front"
		{bone hide "right"}		
		{bone hide "left"}		
		{bone hide "back"}		
		{delay 1
			{bone show "right"}		
			{bone show "left"}		
			{bone show "back"}		
		}
	}
	{on animation_event "back"
		{bone hide "right"}		
		{bone hide "left"}		
		{bone hide "front"}		
		{delay 1
			{bone show "right"}		
			{bone show "left"}		
			{bone show "front"}		
		}
	}
}
