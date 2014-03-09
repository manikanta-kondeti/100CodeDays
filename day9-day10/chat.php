
<?php
session_start();

if($_SESSION['SESS_MEMBER_ID']==NULL)
{
	header('Location: login-form.php');
}
else
{

	$id=  $_POST['halo_id'];
	$uid=  $_POST['uid'];
	$name=$_POST['name'];
	$tid=  $_POST['tid'];

}

?>
<html>
<head>
<title>Chat with <?php echo $name ?></title>
<link href="loginmodule.css" rel="stylesheet" type="text/css" />
</head>
<body>
<a style="margin:1000px" href="./logout.php">Logout</a>
<a style="margin:1000px" href="./myhalos.php">Main</a>
<?php
$con=mysqli_connect("localhost","root","mysql","login");
// Check connection
if (mysqli_connect_errno())
{
	echo "Failed to connect to MySQL: " . mysqli_connect_error();
}

$val =$_SESSION['SESS_MEMBER_ID'];
$halo = mysqli_query($con,"SELECT * FROM halo where halo_id=$id");
$rec = mysqli_query($con,"SELECT * FROM receivers where halo_id=$id");

?>
<!-- Halo heading -->
<div>
<?php

while($row= mysqli_fetch_array($halo))
{
	$message=$row['message'];
	$t=$row['t1'];
	$s=$row['sender'];
	echo "<h1 align='center'>$message</h1>";
	echo "<p align='center' style='margin:5px;'><b>Sender: ";
		$con=mysqli_connect("localhost","root","mysql","login");
		$name = mysqli_query($con,"SELECT * FROM members where member_id=$s");
	while($n=mysqli_fetch_array($name))
	{ 
	echo $n['login'];
	}
	echo "</b></p>";
	echo "<p align='center' style='margin:5px;'><b>$t </b></p>";
}

?>

</div>
<!-- Second table -->
<table border="0" align="center" cellspacing="20">
<thead>
<th>
Responses:
</th>
</thead>
<?php
$con=mysqli_connect("localhost","root","mysql","login");
echo $val;
$flag=0;
$messages = mysqli_query($con,"SELECT * FROM message where thread_id=$tid ");
while($msg=mysqli_fetch_array($messages))
{
	echo "<tr><td>";
	if($msg['sender']==$val)
	{
		echo "<b>You:  </b>";
	}
	else
	{
		echo "<b>He  :</b>";
	}
	echo "</td>";
	echo "<td>";
	echo $msg['message'];
	echo "</td></tr>";
}


echo "
</table>
<form method='POST' action='messageintodb.php'>
<div align='center'>
<textarea name='message' value=''></textarea>
<input type='submit' value='Send'></input>
<input type='hidden' name='sender' value='$val'> </input>
<input type='hidden' name='receiver' value='$uid' ></input>
<input type='hidden' name='thread_id' value='$tid' ></input>
<input type='hidden' name='haloid' value='$id' ></input>
</div>
</form>

</body>
</html>
";


?>
