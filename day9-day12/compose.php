<?php
session_start();

if($_SESSION['SESS_MEMBER_ID']==NULL)
{
	header('Location: login-form.php');
}

	$con=mysqli_connect("localhost","root","mysql","login");
	// Check connection
	if (mysqli_connect_errno())
	{
		echo "Failed to connect to MySQL: " . mysqli_connect_error();
	}

	$result = mysqli_query($con,"SELECT * FROM members");
	mysqli_close($con);
?>
<html>
<head>
<link href="loginmodule.css" rel="stylesheet" type="text/css" />
<title>
Compose Halo
</title>
</head>
<body>
<a href="./logout.php">Logout</a>
<form action="intodb.php" method="POST">
<h1 align="center">New Halo</h1>
<table border="0" cellspacing="30">
<tr>
<td>
<h3>Receivers:</h3>
<table border="0" cellspacing="25">
<thead>
<th>Member Name</th>
<th>Tick</th>
</thead>
<?php
$count=0;
	while($row=mysqli_fetch_array($result))
	{
		if($row['member_id']!=$_SESSION['SESS_MEMBER_ID'])
		{
		$temp = $row['member_id'];
		echo "<tr>";
		echo "<td>";
		echo $row['login'];
		echo "</td>";
		echo "<td>";
		echo "<input type='checkbox' name=$temp ></input>";
		echo "</td>";
		echo "</tr>";
		$count=$temp;
		}
	}
echo "<input type='hidden' name='length' value=$count></input>";
?>
</table>
<td>
<textarea rows="5" cols="60" name="text"></textarea>
</td>
</tr>
</table>
<input type="submit" name="submit"></input>
</form>
</body>
</html>
