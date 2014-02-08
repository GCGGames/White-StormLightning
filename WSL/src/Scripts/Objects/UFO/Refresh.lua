io.write( "" )
function MoveTo( Xdest, val, to )
	if stack:GetInt( "dir" ):Get() == val then
		object:SetDestination( Xdest, 300, 0 )
		object:Calculate()
		if object:GetPosition():GetX() == Xdest then
			object:SetDestroy( true )
		end
	end
end
sprite:SetDraw( true )
MoveTo( 1000, 0, 1 )
MoveTo( 0, 1, 0 )
object:Move()
io.write( "" )
