<?php
session_start();


?>
<html>
<head>
<title>Halos</title>
<link href="loginmodule.css" rel="stylesheet" type="text/css" />
<style type="text/css">
   #your_col {
	         border-left: 1px solid black;
		    }
</style>

</head>
<body>
<a style="margin:1000px" href="./compose.php">Compose</a>
<div  align="center">

<?php
if($_SESSION['SESS_MEMBER_ID']!=NULL)
{
	$con=mysqli_connect("localhost","root","mysql","login");
	// Check connection
	if (mysqli_connect_errno())
	{
		echo "Failed to connect to MySQL: " . mysqli_connect_error();
	}

	$val =$_SESSION['SESS_MEMBER_ID'];
	$result_sent = mysqli_query($con,"SELECT * FROM halo WHERE sender=$val ");
	$result_receivers = mysqli_query($con,"SELECT * FROM receivers WHERE receiver=$val ");
	mysqli_close($con);
}
else 
{
	header('Location: login-form.php');
}
?>

<a href="./logout.php" style="margin:1000px;" >Logout</a>


<h1 align="center">My Halo's  </h1>
<table border="0" cellspacing="10">
<tr>
<td>
<form action="halo-sent.php" method="POST">
<!-- sent -->
<h2>SentHalos</h2>
<table border="0" cellspacing="10">
<thead>
<th>Message</th>
<th>TimeStamp</th>
<th>CheckResponses</th>
</thead>
<?

	if($result_sent!=NULL)
{
while($row = mysqli_fetch_array($result_sent))
{
	$halo_id=$row['halo_id'];
	echo "<tr>";
	echo "<td>";
	echo $row['message'];
	echo "</td>";
	echo "<td>";
	echo $row['t1'];
	echo "</td>";
	echo "<td>";
	echo "<input type='hidden' value=$halo_id name='id'></input>";
	echo "<input type='submit' value='Check'></input>";
	echo "</td>";
	echo "</tr>";
}
}
	else
{
	echo "<tr>";
	echo "<td>";
	echo "None" ;
	echo "</td>";
	echo "</tr>";
}

?>

</table>

</form>
</td>


<td>

<!-- received -->

<form action="halo-received.php" method="POST">
<h2>Received</h2>
<table border="0" cellspacing="10">
<thead>
<th>From</th>
<th>Message</th>
<th>Timestamp</th>
<th>Respond</th>
</thead>
<?php 
$con=mysqli_connect("localhost","root","mysql","login");
while($row1 = mysqli_fetch_array($result_receivers))
{
	echo "<tr>";
	echo "<td>";
	$val_hid= $row1['halo_id'];
	$res = mysqli_query($con,"SELECT * FROM halo WHERE halo_id=$val_hid");

	while($row2 = mysqli_fetch_array($res))
		     {
			     $t=$row2['sender'];

	$halo_id=$row2['halo_id'];
		$res_name = mysqli_query($con,"SELECT login FROM members WHERE member_id=$t");
		     while($row3 = mysqli_fetch_array($res_name))
			     echo $row3['login'];
		      echo "</td>";
		      echo "<td>";
			     echo $row2['message'];
		      echo "</td>";
		      echo "<td>";
			     echo $row2['t1'];
		      echo "</td>";
		      echo "<td>";
	echo "<input type='hidden' value=$halo_id name='id'></input>";
	echo "<input type='submit' value='Respond'></input>";
		     }
		      echo "</td>";
		      echo "</tr>";
		        }
?>

</table>

</td>
</form>
</tr>
</table>
</div>



</body>
</html>

