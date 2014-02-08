c = scanArea:GetCollision()
a = c:GetBooleanValue()
if a == true then
	print( "Collision detected!" )
end
