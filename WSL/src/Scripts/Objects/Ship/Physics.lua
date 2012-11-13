c = scanArea:GetCollision()
--v = c:GetCoords()
a = c:GetBool()
if a == true then
	--print( "Collision!" )
	stack:SetInt( "amount", stack:GetInt( "amount" ):Get() + 1 )
	--print( "Data" )
	size = scanArea:GetCollisionDataSize()
	--print( "Size: ", size )
	--for i = 0, size, 1 do
	--	print( "i: ", i )
	--	print( "ID: ", scanArea:GetACollisionData( i ):GetID() )
	--	print( "Test0" )
	--	print( "Object ID: ", scanArea:GetACollisionData( i ):GetObjectID() )
	--	print( "Test1" )
	--	print( "Component ID: ", scanArea:GetACollisionData( i ):GetComponentID() )
	--	print( "Test2" )
	--	print( "X: ", scanArea:GetACollisionData( i ):GetPoint():GetX() )
	--	print( "Test3" )
	--end
	--print( stack:GetInt( "amount" ):Get() )
	--print( "OBJ OBJID: ", object:GetObjID() )
	--print( "\nOBJ COMPID: ", object:GetComponentID() )
	--print( "SCAN OBJID: ", scanArea:GetObjectID() )
	--print( "SCAN COMPID: ", scanArea:GetComponentID() )
	--object:SetPosition( 500, 500 )
end

