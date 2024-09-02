mv pom.xml pom.xml.old
cp pom.xml-generator pom.xml
mvn clean package
mv pom.xml.old pom.xml
echo "Run it like this: java -jar target/program-generator-2.0.jar <model-name> <Pull-model?true-or-false-flag>"
