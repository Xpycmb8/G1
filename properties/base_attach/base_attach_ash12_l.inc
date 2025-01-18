{bone "upgrade_left_flashlight_sf"
	{parameters "Voxels=0;"}
	{Matrix34
		1	0	0
		0	1	0
		0	0	1
		-0.00580037	0.258624	-0.0415458
	}
	{bone "fx_light_set_l_flashlight_sf"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			0.00438082	1.17932	0.529949
		}
	}
	{bone "flashlight_sf_l_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			1	0	0
			0	1	0
			0	0	1
			-1.45997	-1.56863	0.612843
		}
		{bone "flashlight_sf_l_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.43342	1.92718	-0.073907
			}
			{VolumeView "flashlight_sf_l_ui.ply"}
			{bone "flashlight_sf_l_light_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00157356	0.00700283	-0.00267792
				}
				{VolumeView "flashlight_sf_l_light_on_ui.ply"}
			}
		}
	}
	{bone "flashlight_sf_l"
		{parameters "ID=body;"}
		{Matrix34
			-1	0	0
			0	1	0
			0	0	-1
			0.000486135	0	-7.98106e-05
		}
		{visibility 0}
		{LODView
			{VolumeView "flashlight_sf_l.ply"}
			{VolumeView "flashlight_sf_l_lod1.ply"}
			{VolumeView "flashlight_sf_l_lod2.ply"}
		}
	}
}
{bone "upgrade_left_peq10"
	{parameters "Voxels=0;"}
	{Matrix34
		1	0	0
		0	1	0
		0	0	1
		-0.000715375	-0.180905	-0.0635285
	}
	{bone "fx_laser_set_l_peq10"
		{Matrix34
			-0.000180083	1	0
			0.00018032	0	-1
			-1	-0.000180105	-0.00018032
			-0.190806	0.989472	0.394674
		}
	}
	{bone "an_peq10_l"
		{parameters "ID=body;"}
		{Matrix34
			0	0	1
			0	1	0
			-1	0	0
			-0.00519621	-0.219108	0.109496
		}
		{visibility 0}
		{LODView
			{VolumeView "an_peq10_l.ply"}
			{VolumeView "an_peq10_l_lod1.ply"}
			{VolumeView "an_peq10_l_lod2.ply"}
		}
		{bone "caps_front_l"
			{parameters "ID=body;"}
			{Matrix34
				-0.087157	0.996195	-5.83522e-05
				0.996195	0.0871569	-5.77847e-05
				-5.24791e-05	-6.31664e-05	-1
				0.293141	1.00345	-0.00452995
			}
			{VolumeView "caps_front_l.ply"}
		}
	}
	{bone "peq10_l_ui_bone"
		{parameters "Voxels=0;"}
		{Position -1.19997	-1.95742	0.504414}
		{bone "peq10_l_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.19427	2.01449	-0.0772542
			}
			{VolumeView "peq10_l_ui.ply"}
			{bone "peq10_l_light_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0.00571888	0.999984	0
					1	0	0
					0.00164396	-0.00215912	-0.0123566
				}
				{VolumeView "peq10_l_light_on_ui.ply"}
			}
			{bone "peq10_l_laser_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0.00571888	0.999984	0
					1	0	0
					0.00163186	-0.0123906	-0.0123589
				}
				{VolumeView "peq10_l_laser_on_ui.ply"}
			}
		}
	}
	{bone "fx_light_set_l_peq10"
		{Matrix34
			-0.000180083	1	0
			0.00018032	0	-1
			-1	-0.000180105	-0.00018032
			0.204438	0.989472	0.417448
		}
	}
}
{bone "upgrade_left_peq15"
	{parameters "Voxels=0;"}
	{Matrix34
		1	0	0
		0	1	0
		0	0	1
		-0.0384899	0.0596666	-0.0365338
	}
	{bone "fx_light_set_l_peq15"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.373749	1.25065	0.265302
		}
	}
	{bone "fx_laser_set_l_peq15"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			0.328851	1.00789	0.237556
		}
	}
	{bone "caps_light_l"
		{parameters "ID=body;"}
		{Matrix34
			0	0.984808	0.173648
			0	0.173648	-0.984808
			-1	0	0
			-0.320401	0.887518	0.317423
		}
		{VolumeView "caps_light_l.ply"}
	}
	{bone "caps_laser_l"
		{parameters "ID=body;"}
		{Matrix34
			0	0	1
			-1	0	0
			0	-1	0
			0.297429	0.763119	0.316792
		}
		{VolumeView "caps_laser_l.ply"}
	}
	{bone "peq15_l_ui_bone"
		{parameters "Voxels=0;"}
		{Position -1.32617	-1.38974	0.345396}
		{bone "peq15_l_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.20943	1.88119	-0.0721421
			}
			{VolumeView "peq15_l_ui.ply"}
			{bone "peq15_l_light_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.0015344	0.00678587	-0.00389755
				}
				{VolumeView "peq15_l_light_on_ui.ply"}
			}
			{bone "peq15_l_laser_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00152272	0.00652885	-0.00389755
				}
				{VolumeView "peq15_l_laser_on_ui.ply"}
			}
		}
	}
	{bone "peq15_l"
		{parameters "ID=body;"}
		{Position 8.63075e-05	-0.028439	-0.0280844}
		{visibility 0}
		{LODView
			{VolumeView "peq15_l.ply"}
			{VolumeView "peq15_l_lod1.ply"}
			{VolumeView "peq15_l_lod2.ply"}
		}
	}
}
{bone "upgrade_left_lasercylinder4"
	{parameters "Voxels=0;"}
	{Matrix34
		1	0	0
		0	1	0
		0	0	1
		-0.00551295	0.147366	-0.0420985
	}
	{bone "fx_laser_set_l_lasercylinder4"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			0.00366461	0.829428	0.311058
		}
	}
	{bone "lasercylinder4_l_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			1	0	0
			0	-1	0
			0	0	1
			-1.59892	1.97342	0.35396
		}
		{bone "lasercylinder4_l_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.48044	1.99039	-0.0763313
			}
			{VolumeView "lasercylinder4_l_ui.ply"}
			{bone "lasercylinder4_l_laser_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00162512	0.00723267	-0.00276577
				}
				{VolumeView "lasercylinder4_l_laser_on_ui.ply"}
			}
		}
	}
	{bone "laser_rail_l_lasercylinder4"
		{parameters "ID=body;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.0299776	-0.0537233	0.0496596
		}
		{visibility 0}
		{LODView
			{VolumeView "laser_rail_l_lasercylinder4.ply"}
			{VolumeView "laser_rail_l_lasercylinder4_lod1.ply"}
			{VolumeView "laser_rail_l_lasercylinder4_lod2.ply"}
		}
		{bone "lasercylinder4_l"
			{parameters "ID=body;"}
			{Position 0.270785	-0.25941	-0.032638}
			{visibility 0}
			{LODView
				{VolumeView "lasercylinder4_l.ply"}
				{VolumeView "lasercylinder4_l_lod1.ply"}
				{VolumeView "lasercylinder4_l_lod2.ply"}
			}
		}
	}
}
{bone "upgrade_left_lasercylinder3"
	{parameters "Voxels=0;"}
	{Matrix34
		1	0	0
		0	1	0
		0	0	1
		-0.00515044	0.152564	-0.0411454
	}
	{bone "fx_laser_set_l_lasercylinder3"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			0.00366473	0.724249	0.311058
		}
	}
	{bone "lasercylinder3_l_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			1	0	0
			0	-1	0
			0	0	1
			-1.59892	1.97342	0.35396
		}
		{bone "lasercylinder3_l_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.48044	1.99039	-0.0763314
			}
			{VolumeView "lasercylinder3_l_ui.ply"}
			{bone "lasercylinder3_l_laser_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00162518	0.00723267	-0.00276566
				}
				{VolumeView "lasercylinder3_l_laser_on_ui.ply"}
			}
		}
	}
	{bone "laser_rail_l_lasercylinder3"
		{parameters "ID=body;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.0292548	-0.0537229	0.0483706
		}
		{visibility 0}
		{LODView
			{VolumeView "laser_rail_l_lasercylinder3.ply"}
			{VolumeView "laser_rail_l_lasercylinder3_lod1.ply"}
			{VolumeView "laser_rail_l_lasercylinder3_lod2.ply"}
		}
		{bone "lasercylinder3_l"
			{parameters "ID=body;"}
			{Position 0.242334	-0.262183	-0.0280894}
			{visibility 0}
			{LODView
				{VolumeView "lasercylinder3_l.ply"}
				{VolumeView "lasercylinder3_l_lod1.ply"}
				{VolumeView "lasercylinder3_l_lod2.ply"}
			}
		}
	}
}
{bone "upgrade_left_liner"
	{parameters "Voxels=0;"}
	{Matrix34
		1	0	0
		0	1	0
		0	0	1
		-0.0101123	0.0348291	-0.0387996
	}
	{bone "fx_laser_set_l_liner"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.000597954	1.31889	0.353174
		}
	}
	{bone "liner_l_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			0.999943	-0.00634422	0.00855165
			-0.00639386	-0.999963	0.00579048
			-0.00851458	0.00584485	0.999947
			-1.35546	2.05625	0.217903
		}
		{bone "liner_l_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.41213	1.89855	-0.0728092
			}
			{VolumeView "liner_l_ui.ply"}
			{bone "liner_l_laser_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.0015502	0.00689793	-0.0026381
				}
				{VolumeView "liner_l_laser_on_ui.ply"}
			}
		}
	}
	{bone "liner_l"
		{parameters "ID=body;"}
		{Matrix34
			0	0	-1
			0	1	0
			1	0	0
			-0.00764716	0.258445	-0.0219685
		}
		{visibility 0}
		{LODView
			{VolumeView "liner_l.ply"}
			{VolumeView "liner_l_lod1.ply"}
			{VolumeView "liner_l_lod2.ply"}
		}
	}
}
{bone "upgrade_left_lasercylinder1"
	{parameters "Voxels=0;"}
	{Matrix34
		1	0	0
		0	1	0
		0	0	1
		-0.00893319	0.170781	-0.0414421
	}
	{bone "fx_laser_set_l_lasercylinder1"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			0.0100396	1.11944	0.305457
		}
	}
	{bone "lasercylinder1_l_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			1	0	0
			0	-1	0
			0	0	1
			-1.59892	1.97342	0.35396
		}
		{bone "lasercylinder1_l_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.48044	1.99039	-0.0763314
			}
			{VolumeView "lasercylinder1_l_ui.ply"}
			{bone "lasercylinder1_l_laser_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00162512	0.00723267	-0.00276577
				}
				{VolumeView "lasercylinder1_l_laser_on_ui.ply"}
			}
		}
	}
	{bone "laser_rail_l_lasercylinder1"
		{parameters "ID=body;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.0292546	-0.0537229	0.0461325
		}
		{visibility 0}
		{LODView
			{VolumeView "laser_rail_l_lasercylinder1.ply"}
			{VolumeView "laser_rail_l_lasercylinder1_lod1.ply"}
			{VolumeView "laser_rail_l_lasercylinder1_lod2.ply"}
		}
		{bone "lasercylinder1_l"
			{parameters "ID=body;"}
			{Position 0.250568	-0.261865	-0.0369312}
			{visibility 0}
			{LODView
				{VolumeView "lasercylinder1_l.ply"}
				{VolumeView "lasercylinder1_l_lod1.ply"}
				{VolumeView "lasercylinder1_l_lod2.ply"}
			}
		}
	}
}
{bone "upgrade_left_tactical_laser"
	{parameters "Voxels=0;"}
	{Matrix34
		1	0	0
		0	1	0
		0	0	1
		-0.0108703	0.224539	-0.0342902
	}
	{bone "fx_laser_set_l_tactical_laser"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.159504	0.113316	0.329056
		}
	}
	{bone "tactical_laser_l_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			1	0	0
			0	1	0
			0	0	1
			-1.53424	-2.27922	0.553237
		}
		{bone "tactical_laser_l_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.48044	1.99039	-0.0763314
			}
			{VolumeView "tactical_laser_l_ui.ply"}
			{bone "tactical_laser_l_laser_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00162518	0.00723267	-0.00276577
				}
				{VolumeView "tactical_laser_l_laser_on_ui.ply"}
			}
		}
	}
	{bone "tactical_laser_l"
		{parameters "ID=body;"}
		{Matrix34
			0	1	0
			1	0	0
			0	0	-1
			-0.00161374	-0.286469	0.127427
		}
		{visibility 0}
		{LODView
			{VolumeView "tactical_laser_l.ply"}
			{VolumeView "tactical_laser_l_lod1.ply"}
			{VolumeView "tactical_laser_l_lod2.ply"}
		}
	}
}
{bone "upgrade_left_tactical_laser2"
	{parameters "Voxels=0;"}
	{Matrix34
		1	0	0
		0	1	0
		0	0	1
		-0.00965834	0.221532	-0.0413296
	}
	{bone "fx_laser_set_l_tactical_laser2"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.298707	0.753098	0.13416
		}
	}
	{bone "tactical_laser2_l_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			1	0	0
			0	1	0
			0	0	1
			-1.34647	-2.04576	0.076784
		}
		{bone "tactical_laser2_l_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.48044	1.99039	-0.0763313
			}
			{VolumeView "tactical_laser2_l_ui.ply"}
			{bone "tactical_laser2_l_laser_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00162518	0.00723267	-0.00276577
				}
				{VolumeView "tactical_laser2_l_laser_on_ui.ply"}
			}
		}
	}
	{bone "tactical_laser2_l"
		{parameters "ID=body;"}
		{Matrix34
			0	1	0
			-1	0	0
			0	0	1
			0.0191853	-0.737634	0.10307
		}
		{visibility 0}
		{LODView
			{VolumeView "tactical_laser2_l.ply"}
			{VolumeView "tactical_laser2_l_lod1.ply"}
			{VolumeView "tactical_laser2_l_lod2.ply"}
		}
	}
}
{bone "upgrade_left_zenitco"
	{parameters "Voxels=0;"}
	{Position -0.0151826	-0.237133	-0.0576516}
	{bone "fx_laser_set_l_zenitco"
		{Matrix34
			-0.000180082	1	0
			0.00018032	0	-1
			-1	-0.000180109	-0.00018032
			-0.241392	0.91191	0.239207
		}
	}
	{bone "zenitco_l_ui_bone"
		{parameters "Voxels=0;"}
		{Position -1.07263	-1.63153	0.262957}
		{bone "zenitco_l_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				0.995432	1.6791	-0.064392
			}
			{VolumeView "zenitco_l_ui.ply"}
			{bone "zenitco_l_light_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00136864	0.0742512	-0.146051
				}
				{VolumeView "zenitco_l_light_on_ui.ply"}
			}
			{bone "zenitco_l_laser_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00136721	-0.109684	-0.146051
				}
				{VolumeView "zenitco_l_laser_on_ui.ply"}
			}
		}
	}
	{bone "fx_light_set_l_zenitco"
		{Matrix34
			-0.000180082	1	0
			0.00018032	0	-1
			-1	-0.000180109	-0.00018032
			0.00203753	0.897622	0.592928
		}
	}
	{bone "zenitco_l"
		{parameters "ID=body;"}
		{Matrix34
			0	0	-1
			0	1	0
			1	0	0
			-0.0269499	0.202374	0.465285
		}
		{visibility 0}
		{LODView
			{VolumeView "zenitco_l.ply"}
			{VolumeView "zenitco_l_lod1.ply"}
			{VolumeView "zenitco_l_lod2.ply"}
		}
	}
}
{bone "upgrade_left_laser5mw"
	{parameters "Voxels=0;"}
	{Matrix34
		1	0	0
		0	1	0
		0	0	1
		-0.00810385	-0.331356	-0.0345579
	}
	{bone "fx_laser_set_l_laser5mw"
		{Matrix34
			0.000316384	1	0
			-1	0.000314977	-0.000311371
			-0.000311378	0	1
			-0.0808862	1.00316	0.222586
		}
	}
	{bone "laser5mw_l_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			1	0	0
			0	1	0
			0	0	1
			-1.22008	-1.531	0.372351
		}
		{bone "laser5mw_l_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.17998	1.99039	-0.0763299
			}
			{VolumeView "laser5mw_l_ui.ply"}
			{bone "laser5mw_l_light_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00162238	0.0880175	-0.173128
				}
				{VolumeView "laser5mw_l_light_on_ui.ply"}
			}
			{bone "laser5mw_l_laser_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00162077	-0.130018	-0.173128
				}
				{VolumeView "laser5mw_l_laser_on_ui.ply"}
			}
		}
	}
	{bone "fx_light_set_l_laser5mw"
		{Matrix34
			0.000316384	1	0
			-1	0.000314977	-0.000311371
			-0.000311378	0	1
			0.0233531	1.02438	0.373039
		}
	}
	{bone "laser5mw_l"
		{parameters "ID=body;"}
		{Matrix34
			0	1	-0.000678396
			1	0	0
			0	-0.000678404	-1
			0.000649333	0.287245	0.120421
		}
		{visibility 0}
		{LODView
			{VolumeView "laser5mw_l.ply"}
			{VolumeView "laser5mw_l_lod1.ply"}
			{VolumeView "laser5mw_l_lod2.ply"}
		}
	}
}
{bone "upgrade_left_laser1mw"
	{parameters "Voxels=0;"}
	{Matrix34
		1	0	0
		0	1	0
		0	0	1
		-0.0124453	-0.218749	-0.0375633
	}
	{bone "fx_laser_set_l_laser1mw"
		{Matrix34
			0.000316384	1	0
			-1	0.000314977	-0.000311371
			-0.000311378	0	1
			0.00247133	0.572751	0.770947
		}
	}
	{bone "laser1mw_l_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			1	0	0
			0	1	0
			0	0	1
			-1.26156	-1.41372	0.432593
		}
		{bone "laser1mw_l_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.17998	1.99039	-0.0763299
			}
			{VolumeView "laser1mw_l_ui.ply"}
			{bone "laser1mw_l_light_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00162238	0.0880175	-0.173128
				}
				{VolumeView "laser1mw_l_light_on_ui.ply"}
			}
			{bone "laser1mw_l_laser_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00162071	-0.130018	-0.173128
				}
				{VolumeView "laser1mw_l_laser_on_ui.ply"}
			}
		}
	}
	{bone "fx_light_set_l_laser1mw"
		{Matrix34
			0.000316384	1	0
			-1	0.000314977	-0.000311371
			-0.000311378	0	1
			0.0020628	1.36239	0.393348
		}
	}
	{bone "laser_1mw_l"
		{parameters "ID=body;"}
		{Matrix34
			0	1	0
			1	0	0
			0	0	-1
			0.00418043	0.0621052	0.12509
		}
		{visibility 0}
		{LODView
			{VolumeView "laser_1mw_l.ply"}
			{VolumeView "laser_1mw_l_lod1.ply"}
			{VolumeView "laser_1mw_l_lod2.ply"}
		}
	}
}