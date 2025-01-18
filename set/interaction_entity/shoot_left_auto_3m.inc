{if tagged "empty_auto"
	{start_sound "weapon/shell_eject/shell12"}	
	{tags remove "2_auto"}
	{tags add "0_auto"}
	{tags add "empty_key"}
	{tags add "reset"}
else tagged "2_auto" 
	{tags add "empty_auto"}
	{tags remove "0_auto"}
else tagged "1_auto" 
	{tags add "2_auto"}
	{tags remove "1_auto"}
else tagged "0_auto" ;first shot
	{tags remove "reset"}
	{tags remove "0_auto"}
	{tags add "1_auto"}
}