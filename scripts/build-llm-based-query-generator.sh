mv pom.xml pom.xml.old
cp pom.xml-query pom.xml
mvn clean package
mv pom.xml.old pom.xml
echo "Run it like this: java -jar target/query-generator-2.0.jar 0 ==> starting query for the LLM"
echo "Run it like this: java -jar target/query-generator-2.0.jar 1 ==> A query for the LLM"
echo "Run it like this: java -jar target/query-generator-2.0.jar 2 <ANSWER FROM LLM> ==> parsing the query's response for the LLM"
