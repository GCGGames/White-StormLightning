stack:SetInt( "count", stack:GetInt( "count" ):Get() + 1 )

if stack:GetInt( "count" ):Get() >= 50 and stack:GetInt( "count" ):Get() <= 60 then
	singleton:Instantiate( "bin/Info/Objects/Ship/Object.txt" )
	level:AddObject( stack:GetInt( "add" ):Get(), 1 )
	print( stack:GetInt( "count" ):Get() )
end


if stack:GetInt( "count" ):Get() >= 200 and stack:GetInt( "count" ):Get() < 300 then
	stack:SetInt( "count", 0 )
	singleton:Instantiate( "bin/Info/Objects/UFO/Object.txt" )
	level:AddObject( stack:GetInt( "add" ):Get(), 0 )
end

if stack:GetInt( "levelCount" ):Get() == 600 then
	level:SetDestroy( true )
	level:SetActive( false )
	print( "Changing to level2!" )
	singleton:InstantiateLevel( "bin/Info/Levels/Example2/Level.txt" )
end
