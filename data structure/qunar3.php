<?php
$handle = fopen ("php://stdin","r");
$src = fgets($handle);
while ($src != "") {
	$dit = fgets($handle);
	$list = explode(" ", fgets($handle));
	$len = strlen($src);
	$count = 0;
	for ($i = 0, $j = 0; $i < $len, $j < $len; $i ++, $j ++) {
		if ($src[$i] != $dit[$j]) {
			$a[$i] = $dit[$j];
		}
	}
	for ($i = 0; $i < count($a); $i ++) {
		for ($j = 0; $j < count($list); $j ++) {
			if (isset($a[$i])) {
				for ($k = 0; $k < strlen($list[$j]); $k ++) {
					if ($a[$i] == $list[$j][$k]) {
						$count ++;
					}
				} 
			}
		}
	}
	echo $count.PHP_EOL;
	$src = fgets($handle);
}
fclose($handle);

// $src = fread(STDIN, 1000);
// $dit = fread(STDIN, 1000);
// $list = explode(" ", fread(STDIN, 1000));