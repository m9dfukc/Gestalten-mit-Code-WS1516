<!DOCTYPE html>
<html>
<head>

</head>
<body>

  <form enctype="multipart/form-data" action="formular.php" method="post">
    <div>
        <label for="name">Name:</label>
        <input type="text" name="name" id="name" />
    </div>
    <div>
        <label for="mail">E-mail:</label>
        <input type="email" name="email" id="mail" />
    </div>
    <div>
        <label for="cv">CV Image:</label>
        <input type="file" name="userfile" id="file" />
    </div>
    <input type="submit" value="submit" />

  </form>
  <br>
  <br>

  <?php
    $file = 'data.txt';
    $images = 'images.txt';
    $current = file_get_contents($file);
    $current_images = file_get_contents($images);

    if (isset($_POST['name']) || isset($_POST['email'])) {
      $current .= $_POST['name'] . ", " . $_POST['email'] . "\n";
      file_put_contents($file, $current);
    }
  ?>
  
  <ul>
    <?php 
      $lines = explode("\n", $current);
      for ($i=0; $i < count($lines); $i++) {
        echo "<li>" . $lines[$i] . "</li>";
      }
    ?>
  <ul>

  <?php 
    if(isset($_FILES['userfile'])) {
      echo "<img src='".$_FILE['userfile']['cv'] . "/>";
      $img = file_get_contents( $_FILES['userfile']['tmp_name'] );
      $current_images .= $img . "\n\n";
      file_put_contents($images, $current_images);
    }
  ?>


</body>
</html>