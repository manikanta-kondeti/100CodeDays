<?php
session_start();

if($_SESSION['SESS_MEMBER_ID']==NULL)
{
	header('Location: login-form.php');
}
for($i=1;$i<=$_POST['length'];$i++)
{
if(isset($_POST[$i]))
{
	echo $i;
}
}
$sender=$_SESSION['SESS_MEMBER_ID'];
$text=$_POST['text'];

	$con=mysqli_connect("localhost","root","mysql","login");
	// Check connection
	if (mysqli_connect_errno())
	{
		echo "Failed to connect to MySQL: " . mysqli_connect_error();
	}

$sql_halo = "INSERT INTO halo ".
       "(sender , message) ".
              "VALUES ".
	             "('$sender','$text')";


//for halo sql 
		     
$retval_insert = mysqli_query(  $con ,$sql_halo);
if(! $retval_insert )
{
	  die('Could not enter data: ' . mysql_error());
}


$last_hid= "SELECT MAX(halo_id) FROM halo";

//for last id
$retval = mysqli_query( $con ,$last_hid);
if(! $retval )
{
	  die('Could not enter data: qq' . mysql_error());
}

// Highest id part 
while($row = mysqli_fetch_array($retval))
{
echo "hi";
echo $row;
$value=0;
foreach($row as $val)
{
	$value=$val;
}
}

for($i=1;$i<$_POST['length'];$i++)
{
	if(isset($_POST[$i]))
	{
		mysqli_query($con, "insert into receivers (halo_id , receiver) values ($value  , $i)");
	}
}
echo "Success";
header('Location: myhalos.php');
?>
