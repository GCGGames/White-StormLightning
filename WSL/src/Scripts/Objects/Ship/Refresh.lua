
sprite:SetDraw( true )
stack:SetInt( "a", stack:GetInt( "a" ):Get() + 1 )
if stack:GetInt( "a" ):Get() >= 531 then
	stack:SetInt( "a", 0 )
	object:SetDestroy( true )
	print( "Boom goes the ship!" )
end
