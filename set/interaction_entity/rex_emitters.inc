(define "rex_emitters"
	{"%tag"
		{on spawn
			{link_sound "amb_emitters" "amb_emitters/stressmetal/%tag/"}
			{delay 90 45
				{call "amb_emitters"}
			}
		}
		{on "amb_emitters"
			;{stop_sound "amb_emitters"}
			{if rand 0.2
				{if not burned
					{if not fallen
						{play_sound "amb_emitters" }
						{delay_effect 120 40 "amb_emitters"}
					}
				}
			}
		}
		{on ground_hit
			{if contact_velocity 8
				{if not "burned"
					{if not "broken"
						{if rand 0.2
							{start_sound "rex_emitters/%tag/"}
							{if "fence"
								{burn volume fx "rex_emitters_fence" time 1 fake even_law}
							else "old_steel"
								{burn volume fx "rex_emitters_steel" time 1 fake even_law}
							else "emitters_pipes"
								{burn volume fx "rex_emitters_pipes" time 1 fake even_law}
							else "old_wood"
								{burn volume fx "rex_emitters_fence" time 1 fake even_law}
							}								
						}	
					}
				}
			}	
		}	
		{on pierce
			{if not volume "setting_frame"	
				{if not material "wound_glass"
					{if not "burned"
						{if not "broken"
							{if stuff "hmgun"
								{if rand 0.3
									{start_sound "rex_emitters/%tag/"}
									{if "fence"
										{burn volume fx "rex_emitters_fence" time 1 fake even_law}
									else "old_steel"
										{burn volume fx "rex_emitters_steel" time 1 fake even_law}
									else "emitters_pipes"
										{burn volume fx "rex_emitters_pipes" time 1 fake even_law}
									else "old_wood"
										{burn volume fx "rex_emitters_fence" time 1 fake even_law}
									}								
								}								
							else stuff "shell"
								{if rand 0.5
									{start_sound "rex_emitters/%tag/"}
									{if "fence"
										{burn volume fx "rex_emitters_fence" time 1 fake even_law}
									else "old_steel"
										{burn volume fx "rex_emitters_steel" time 1 fake even_law}
									else "emitters_pipes"
										{burn volume fx "rex_emitters_pipes" time 1 fake even_law}
									else "old_wood"
										{burn volume fx "rex_emitters_fence" time 1 fake even_law}
									}								
								}								
							else stuff "bullet"
								{if rand 0.1
									{start_sound "rex_emitters/%tag/"}
									{if "fence"
										{burn volume fx "rex_emitters_fence" time 1 fake even_law}
									else "old_steel"
										{burn volume fx "rex_emitters_steel" time 1 fake even_law}
									else "emitters_pipes"
										{burn volume fx "rex_emitters_pipes" time 1 fake even_law}
									else "old_wood"
										{burn volume fx "rex_emitters_fence" time 1 fake even_law}
									}								
								}	
							}	
						}
					}
				}	
			}	
		}	
		{on blast
			{if not "burned"
				{if not "broken"
					{if min_energy 5
						{if rand 0.9
							{if prop "modded"
								{if volume "cabin"
									{if hit_side front
										{tags add "front"}
										{ani_play "hit_side_front_emitters" 0.6}								
									else hit_side back
										{ani_play "hit_side_back_emitters" 0.6}								
										{tags add "back"}
									else 
										{ani_play "hit_side_left_right_emitters" 0.6}								
										{tags add "left"}
									}								
								}								
							}
							{start_sound "rex_emitters/%tag/"}
							{ani_play "emitters" 1.5}
							{if prop "emitters_concrete_fence"
								{burn volume fx "rex_emitters_fence" time 3 fake even_law}
							else "old_steel"
								{burn volume fx "rex_emitters_steel" time 2 fake even_law}
							else "emitters_pipes"
								{burn volume fx "rex_emitters_pipes" time 2 fake even_law}
							else "old_wood"
								{burn volume fx "rex_emitters_fence" time 2 fake even_law}
							}
						}	
					else min_energy 2
						{if rand 0.5
							{if prop "modded"
								{if volume "cabin"
									{if hit_side front
										{tags add "front"}
										{ani_play "hit_side_front_emitters" 0.6}								
									else hit_side back
										{ani_play "hit_side_back_emitters" 0.6}								
										{tags add "back"}
									else 
										{ani_play "hit_side_left_right_emitters" 0.6}								
										{tags add "left"}
									}								
								}								
							}
							{start_sound "rex_emitters/%tag/"}
							{ani_play "emitters" 1}
							{if prop "emitters_concrete_fence"
								{burn volume fx "rex_emitters_fence" time 2 fake even_law}
							else "old_steel"
								{burn volume fx "rex_emitters_steel" time 2 fake even_law}
							else "emitters_pipes"
								{burn volume fx "rex_emitters_pipes" time 2 fake even_law}
							else "old_wood"
								{burn volume fx "rex_emitters_fence" time 2 fake even_law}
							}
						}	
					else min_energy 0.5
						{if rand 0.5
							{if prop "modded"
								{if volume "cabin"
									{if hit_side front
										{tags add "front"}
										{ani_play "hit_side_front_emitters" 0.6}								
									else hit_side back
										{ani_play "hit_side_back_emitters" 0.6}								
										{tags add "back"}
									else 
										{ani_play "hit_side_left_right_emitters" 0.6}								
										{tags add "left"}
									}								
								}								
							}
							{start_sound "rex_emitters/%tag/"}
							{if prop "emitters_concrete_fence"
								{burn volume fx "rex_emitters_fence" time 2 fake even_law}
							else "old_steel"
								{burn volume fx "rex_emitters_steel" time 2 fake even_law}
							else "emitters_pipes"
								{burn volume fx "rex_emitters_pipes" time 2 fake even_law}
							else "old_wood"
								{burn volume fx "rex_emitters_fence" time 2 fake even_law}
							}
						}	
					}	
				}
				{if "exploded"				
					{if rand 0.5 
						{start_sound "rex_emitters/emitters_pipes_big/"}
					}	
				}	
			}
		}	
	}	
)
("rex_emitters" tag(emitters_short))
("rex_emitters" tag(emitters_plastic))
("rex_emitters" tag(emitters_car))
("rex_emitters" tag(emitters_wire))
("rex_emitters" tag(emitters_tunnel))
("rex_emitters" tag(emitters_glass))
("rex_emitters" tag(emitters_steel_solid))
("rex_emitters" tag(emitters_grate))
("rex_emitters" tag(emitters_panel))
("rex_emitters" tag(emitters_pipes))
("rex_emitters" tag(emitters_concrete))
("rex_emitters" tag(emitters_concrete_fence))
("rex_emitters" tag(emitters_light_metalls))
("rex_emitters" tag(emitters_pipes_big))
("rex_emitters" tag(emitters_big_barrel))
("rex_emitters" tag(emitters_cornered))
("rex_emitters" tag(emitters_wood_heavy))
("rex_emitters" tag(emitters_wood_small))
("rex_emitters" tag(emitters_wood_solid))

{"massive_industrial"
	{on spawn
		{link_sound "amb_emitters" "amb_emitters/dist/"}
		{delay 15 5
			{call "amb_emitters_industrial"}
		}
	}
	{on "amb_emitters_industrial"
		{if rand 0.2
			{if not burned
				{if not fallen
					{play_sound "amb_emitters" }
					{delay_effect 210 50 "amb_emitters_industrial"}
				}
			}
		}
	}
}
