{bone "upgrade_upper_tactical_laser"
	{parameters "Voxels=0;"}
	{Matrix34
		0	-1	0
		1	0	0
		0	0	1
		2.59219	-0.00202879	0.508768
	}
	{bone "fx_laser_set_up_tactical_laser"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.156603	0.111255	0.323072
		}
	}
	{bone "tactical_laser_up_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			0	0	-1
			0	1	0
			1	0	0
			-0.0151092	-2.10228	1.83955
		}
		{bone "tactical_laser_up_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.45352	1.9542	-0.0749431
			}
			{VolumeView "tactical_laser_up_ui.ply"}
			{bone "tactical_laser_up_laser_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.0015956	0.00710106	-0.00271553
				}
				{VolumeView "tactical_laser_up_laser_on_ui.ply"}
			}
		}
	}
	{bone "tactical_laser_up"
		{parameters "ID=body;"}
		{visibility 0}
		{Matrix34
			0	1	0
			1	0	0
			0	0	-1
			-0.00158436	-0.28126	0.12511
		}
		{LODView
			{VolumeView "tactical_laser_up.ply"}
			{VolumeView "tactical_laser_up_lod1.ply"}
			{VolumeView "tactical_laser_up_lod2.ply"}
		}
	}
}
{bone "upgrade_upper_lasercylinder1"
	{parameters "Voxels=0;"}
	{Matrix34
		0	-1	0
		1	0	0
		0	0	1
		2.5321	-0.00296462	0.513812
	}
	{bone "fx_laser_set_up_lasercylinder1"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			0.0100144	1.11662	0.304689
		}
	}
	{bone "lasercylinder1_up_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			0	0	-1
			0	-1	0
			1	0	0
			-0.00674673	1.86473	1.76353
		}
		{bone "lasercylinder1_up_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.47672	1.98539	-0.0761394
			}
			{VolumeView "lasercylinder1_up_ui.ply"}
			{bone "lasercylinder1_up_laser_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00162107	0.00721455	-0.00275892
				}
				{VolumeView "lasercylinder1_up_laser_on_ui.ply"}
			}
		}
	}
	{bone "laser_rail_up_lasercylinder1"
		{visibility 0}
		{parameters "ID=body;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.0291812	-0.0535879	0.0460166
		}
		{VolumeView "laser_rail_up_lasercylinder1.ply"}
		{bone "lasercylinder1_up"
			{parameters "ID=body;"}
			{Position 0.249939	-0.261207	-0.0368382}
			{LODView
				{VolumeView "lasercylinder1_up.ply"}
				{VolumeView "lasercylinder1_up_lod1.ply"}
				{VolumeView "lasercylinder1_up_lod2.ply"}
			}
		}
	}
}
{bone "upgrade_upper_tactical_laser2"
	{parameters "Voxels=0;"}
	{Matrix34
		0	-1	0
		1	0	0
		0	0	1
		2.94421	0.00135914	0.508426
	}
	{bone "fx_laser_set_up_tactical_laser2"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.304358	0.767346	0.136698
		}
	}
	{bone "tactical_laser2_up_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			0	0	-1
			0	1	0
			1	0	0
			0.00127889	-2.05151	1.68599
		}
		{bone "tactical_laser2_up_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.50845	2.02805	-0.0777754
			}
			{VolumeView "tactical_laser2_up_ui.ply"}
			{bone "tactical_laser2_up_laser_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00165591	0.00736904	-0.00281817
				}
				{VolumeView "tactical_laser2_up_laser_on_ui.ply"}
			}
		}
	}
	{bone "tactical_laser2_up"
		{visibility 0}
		{parameters "ID=body;"}
		{Matrix34
			0	1	0
			-1	0	0
			0	0	1
			0.0195483	-0.75159	0.10502
		}
		{LODView
			{VolumeView "tactical_laser2_up.ply"}
			{VolumeView "tactical_laser2_up_lod1.ply"}
			{VolumeView "tactical_laser2_up_lod2.ply"}
		}
	}
}
{bone "upgrade_upper_laser1mw"
	{parameters "Voxels=0;"}
	{Matrix34
		0	-1	0
		1	0	0
		0	0	1
		2.18414	0.00242047	0.511784
	}
	{bone "fx_laser_set_up_laser1mw"
		{Matrix34
			0.000315825	1	0
			-1	0.000315535	-0.000311378
			-0.000311371	0	1
			0.0024852	0.576019	0.775348
		}
	}
	{bone "laser1mw_up_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			0	0	-1
			0	1	0
			1	0	0
			0.00456849	-1.86851	1.64201
		}
		{bone "laser1mw_up_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.18672	2.00175	-0.0767653
			}
			{VolumeView "laser1mw_up_ui.ply"}
			{bone "laser1mw_up_light_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00163164	0.0885201	-0.174116
				}
				{VolumeView "laser1mw_up_light_on_ui.ply"}
			}
			{bone "laser1mw_up_laser_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00162997	-0.13076	-0.174116
				}
				{VolumeView "laser1mw_up_laser_on_ui.ply"}
			}
		}
	}
	{bone "fx_light_set_up_laser1mw"
		{Matrix34
			0.000315825	1	0
			-1	0.000315535	-0.000311378
			-0.000311371	0	1
			0.00207403	1.37017	0.395593
		}
	}
	{bone "laser_1mw_up"
		{visibility 0}
		{parameters "ID=body;"}
		{Matrix34
			0	1	0
			1	0	0
			0	0	-1
			0.00420434	0.0624599	0.125804
		}
		{LODView
			{VolumeView "laser_1mw_up.ply"}
			{VolumeView "laser_1mw_up_lod1.ply"}
			{VolumeView "laser_1mw_up_lod2.ply"}
		}
	}
}
{bone "upgrade_upper_peq10"
	{parameters "Voxels=0;"}
	{Matrix34
		0	-1	0
		1	0	0
		0	0	1
		2.22377	-0.0058154	0.489221
	}
	{bone "fx_laser_set_up_peq10"
		{Matrix34
			-0.000180075	1	0
			0.00018032	0	-1
			-1	-0.000180098	-0.00018032
			-0.180568	0.936384	0.373498
		}
	}
	{bone "an_peq10_up"
		{visibility 0}
		{parameters "ID=body;"}
		{Matrix34
			0	0	1
			0	1	0
			-1	0	0
			-0.00491739	-0.207352	0.103621
		}
		{LODView
			{VolumeView "an_peq10_up.ply"}
			{VolumeView "an_peq10_up_lod1.ply"}
		}
		{bone "caps_front_up"
			{parameters "ID=body;"}
			{Matrix34
				-0.0871569	0.996195	-5.84051e-05
				0.996195	0.0871568	-5.80231e-05
				-5.27119e-05	-6.32399e-05	-1
				0.277413	0.949616	-0.00428779
			}
			{VolumeView "caps_front_up.ply"}
		}
	}
	{bone "peq10_up_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			0	0	-1
			0	1	0
			1	0	0
			-0.0132589	-1.53233	1.55267
		}
		{bone "peq10_up_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.13019	1.90641	-0.0731092
			}
			{VolumeView "peq10_up_ui.ply"}
			{bone "peq10_up_light_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00155391	0.0843039	-0.165823
				}
				{VolumeView "peq10_up_light_on_ui.ply"}
			}
			{bone "peq10_up_laser_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00155234	-0.124532	-0.165823
				}
				{VolumeView "peq10_up_laser_on_ui.ply"}
			}
		}
	}
	{bone "fx_light_set_up_peq10"
		{Matrix34
			-0.000180075	1	0
			0.00018032	0	-1
			-1	-0.000180098	-0.00018032
			0.193469	0.936384	0.39505
		}
	}
}
{bone "upgrade_upper_liner"
	{parameters "Voxels=0;"}
	{Matrix34
		0	-1	0
		1	0	0
		0	0	1
		2.25702	0.00131649	0.514456
	}
	{bone "fx_laser_set_up_liner"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.000606918	1.33877	0.358498
		}
	}
	{bone "liner_up_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			0	0	-1
			0	-1	0
			1	0	0
			0.000146765	1.88231	1.02563
		}
		{bone "liner_up_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.43342	1.92717	-0.0739067
			}
			{VolumeView "liner_up_ui.ply"}
			{bone "liner_up_laser_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00157354	0.00700283	-0.00267797
				}
				{VolumeView "liner_up_laser_on_ui.ply"}
			}
		}
	}
	{bone "liner_up"
		{visibility 0}
		{parameters "ID=body;"}
		{Matrix34
			0	0	-1
			0	1	0
			1	0	0
			-0.00776239	0.262341	-0.0222998
		}
		{LODView
			{VolumeView "liner_up.ply"}
			{VolumeView "liner_up_lod1.ply"}
			{VolumeView "liner_up_lod2.ply"}
		}
	}
}
{bone "upgrade_upper_flashlight_sf"
	{parameters "Voxels=0;"}
	{Matrix34
		0	-1	0
		1	0	0
		0	0	1
		3.22211	-0.000778656	0.507008
	}
	{bone "flashlight_sf_up"
		{visibility 0}
		{parameters "ID=body;"}
		{Matrix34
			-1	0	0
			0	1	0
			0	0	-1
			0.000507169	0	-8.32975e-05
		}
		{LODView
			{VolumeView "flashlight_sf_up.ply"}
			{VolumeView "flashlight_sf_up_lod1.ply"}
			{VolumeView "flashlight_sf_up_lod2.ply"}
		}
	}
	{bone "fx_light_set_up_flashlight_sf"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			0.00456991	1.23024	0.552831
		}
	}
	{bone "flashlight_sf_up_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			0	0	-1
			0	1	0
			1	0	0
			-0.00717922	-1.67143	1.99077
		}
		{bone "flashlight_sf_up_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.49531	2.01039	-0.0770981
			}
			{VolumeView "flashlight_sf_up_ui.ply"}
			{bone "flashlight_sf_up_light_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00164149	0.00730515	-0.00279361
				}
				{VolumeView "flashlight_sf_up_light_on_ui.ply"}
			}
		}
	}
}
{bone "upgrade_upper_laser5mw"
	{parameters "Voxels=0;"}
	{Matrix34
		0	-1	0
		1	0	0
		0	0	1
		2.10924	-0.000402989	0.512615
	}
	{bone "fx_laser_set_up_laser5mw"
		{Matrix34
			0.000315641	1	0
			-1	0.000315718	-0.000311379
			-0.00031137	0	1
			-0.0829538	1.02879	0.228273
		}
	}
	{bone "laser5mw_up_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			0	0	-1
			0	1	0
			1	0	0
			0.00231281	-1.55414	1.62667
		}
		{bone "laser5mw_up_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.21013	2.04125	-0.0782803
			}
			{VolumeView "laser5mw_up_ui.ply"}
			{bone "laser5mw_up_light_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00166381	0.0902662	-0.177551
				}
				{VolumeView "laser5mw_up_light_on_ui.ply"}
			}
			{bone "laser5mw_up_laser_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00166216	-0.13334	-0.177551
				}
				{VolumeView "laser5mw_up_laser_on_ui.ply"}
			}
		}
	}
	{bone "fx_light_set_up_laser5mw"
		{Matrix34
			0.000315641	1	0
			-1	0.000315718	-0.000311379
			-0.00031137	0	1
			0.023949	1.05055	0.38257
		}
	}
	{bone "laser5mw_up"
		{visibility 0}
		{parameters "ID=body;"}
		{Matrix34
			0	1	-0.000678397
			1	0	0
			0	-0.000678404	-1
			0.0006657	0.294584	0.123498
		}
		{LODView
			{VolumeView "laser5mw_up.ply"}
			{VolumeView "laser5mw_up_lod1.ply"}
			{VolumeView "laser5mw_up_lod2.ply"}
		}
	}
}
{bone "upgrade_upper_zenitco"
	{parameters "Voxels=0;"}
	{Matrix34
		0	-1	0
		1	0	0
		0	0	1
		2.2017	0.00142001	0.498599
	}
	{bone "fx_laser_set_up_zenitco"
		{Matrix34
			-0.000180082	1	0
			0.00018032	0	-1
			-1	-0.000180082	-0.00018032
			-0.238425	0.900699	0.236266
		}
	}
	{bone "zenitco_up_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			0	0	-1
			0	1	0
			1	0	0
			0.0074485	-1.40992	1.6446
		}
		{bone "zenitco_up_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				0.983194	1.65845	-0.0636003
			}
			{VolumeView "zenitco_up_ui.ply"}
			{bone "zenitco_up_light_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.0013518	0.0733385	-0.144255
				}
				{VolumeView "zenitco_up_light_on_ui.ply"}
			}
			{bone "zenitco_up_laser_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00135045	-0.108335	-0.144255
				}
				{VolumeView "zenitco_up_laser_on_ui.ply"}
			}
		}
	}
	{bone "fx_light_set_up_zenitco"
		{Matrix34
			-0.000180082	1	0
			0.00018032	0	-1
			-1	-0.000180082	-0.00018032
			0.00201247	0.886586	0.585638
		}
	}
	{bone "zenitco_up"
		{visibility 0}
		{parameters "ID=body;"}
		{Matrix34
			0	0	-1
			0	1	0
			1	0	0
			-0.0266184	0.199886	0.459564
		}
		{LODView
			{VolumeView "zenitco_up.ply"}
			{VolumeView "zenitco_up_lod1.ply"}
			{VolumeView "zenitco_up_lod2.ply"}
		}
	}
}
{bone "upgrade_upper_peq15"
	{parameters "Voxels=0;"}
	{Matrix34
		0	-1	0
		1	0	0
		0	0	1
		2.29515	0.0265565	0.501765
	}
	{bone "peq15_up"
		{visibility 0}
		{parameters "ID=body;"}
		{Position 9.26368e-05	-0.0305195	-0.0301392}
		{LODView
			{VolumeView "peq15_up.ply"}
			{VolumeView "peq15_up_lod1.ply"}
			{VolumeView "peq15_up_lod2.ply"}
		}
	}
	{bone "fx_light_set_up_peq15"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.401094	1.34215	0.284713
		}
	}
	{bone "fx_laser_set_up_peq15"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			0.352912	1.08164	0.254936
		}
	}
	{bone "caps_light_up"
		{parameters "ID=body;"}
		{Matrix34
			0	0.984808	0.173648
			0	0.173648	-0.984808
			-1	0	0
			-0.343844	0.952455	0.340648
		}
		{VolumeView "caps_light_up.ply"}
	}
	{bone "caps_laser_up"
		{parameters "ID=body;"}
		{Matrix34
			0	0	1
			-1	0	0
			0	-1	0
			0.31919	0.818954	0.339971
		}
		{VolumeView "caps_laser_up.ply"}
	}
	{bone "peq15_up_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			0	0	-1
			0	1	0
			1	0	0
			0.0398364	-1.96488	1.6927
		}
		{bone "peq15_up_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.29791	2.01883	-0.0774204
			}
			{VolumeView "peq15_up_ui.ply"}
			{bone "peq15_up_light_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00164668	0.00728226	-0.0041827
				}
				{VolumeView "peq15_up_light_on_ui.ply"}
			}
			{bone "peq15_up_laser_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00163413	0.00700665	-0.00418276
				}
				{VolumeView "peq15_up_laser_on_ui.ply"}
			}
		}
	}
}
{bone "upgrade_upper_lasercylinder4"
	{parameters "Voxels=0;"}
	{Matrix34
		0	-1	0
		1	0	0
		0	0	1
		2.53152	-0.00138232	0.510897
	}
	{bone "fx_laser_set_up_lasercylinder4"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			0.00357975	0.810223	0.303856
		}
	}
	{bone "lasercylinder4_up_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			0	0	-1
			0	-1	0
			1	0	0
			0.000147453	1.71367	1.03475
		}
		{bone "lasercylinder4_up_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.44616	1.94431	-0.0745638
			}
			{VolumeView "lasercylinder4_up_ui.ply"}
			{bone "lasercylinder4_up_laser_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00158753	0.00706482	-0.00270178
				}
				{VolumeView "lasercylinder4_up_laser_on_ui.ply"}
			}
		}
	}
	{bone "laser_rail_up_lasercylinder4"
		{visibility 0}
		{parameters "ID=body;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.0292834	-0.0524797	0.0485097
		}
		{LODView
			{VolumeView "laser_rail_up_lasercylinder4.ply"}
			{VolumeView "laser_rail_up_lasercylinder4_lod1.ply"}
			{VolumeView "laser_rail_up_lasercylinder4_lod2.ply"}
		}
		{bone "lasercylinder4_up"
			{parameters "ID=body;"}
			{Position 0.264516	-0.253404	-0.0318822}
			{LODView
				{VolumeView "lasercylinder4_up.ply"}
				{VolumeView "lasercylinder4_up_lod1.ply"}
				{VolumeView "lasercylinder4_up_lod2.ply"}
			}
		}
	}
}
{bone "upgrade_upper_lasercylinder3"
	{parameters "Voxels=0;"}
	{Matrix34
		0	-1	0
		1	0	0
		0	0	1
		2.66354	-0.000165796	0.511203
	}
	{bone "fx_laser_set_up_lasercylinder3"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			0.00361279	0.714007	0.30666
		}
	}
	{bone "lasercylinder3_up_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			0	0	-1
			0	-1	0
			1	0	0
			0.00014922	1.88018	1.0443
		}
		{bone "lasercylinder3_up_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.45951	1.96225	-0.0752519
			}
			{VolumeView "lasercylinder3_up_ui.ply"}
			{bone "lasercylinder3_up_laser_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00160218	0.00713062	-0.00272671
				}
				{VolumeView "lasercylinder3_up_laser_on_ui.ply"}
			}
		}
	}
	{bone "laser_rail_up_lasercylinder3"
		{visibility 0}
		{parameters "ID=body;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.028841	-0.0529633	0.0476866
		}
		{LODView
			{VolumeView "laser_rail_up_lasercylinder3.ply"}
			{VolumeView "laser_rail_up_lasercylinder3_lod1.ply"}
			{VolumeView "laser_rail_up_lasercylinder3_lod2.ply"}
		}
		{bone "lasercylinder3_up"
			{parameters "ID=body;"}
			{Position 0.238908	-0.258476	-0.0276921}
			{LODView
				{VolumeView "lasercylinder3_up.ply"}
				{VolumeView "lasercylinder3_up_lod1.ply"}
				{VolumeView "lasercylinder3_up_lod2.ply"}
				{VolumeView "lasercylinder3_up_lod3.ply"}
			}
		}
	}
}
