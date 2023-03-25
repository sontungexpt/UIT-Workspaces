import React from 'react';
import { Text, Image, View, StyleSheet } from 'react-native';

function Product({
  name,
  url,
  description,
  isInDetail,
}: {
  name?: string;
  url?: string;
  description?: string;
  isInDetail?: boolean;
}) {
  return (
    <View style={isInDetail ? styles.detailContainer : styles.container}>
      <Image style={styles.img} source={{ uri: url }} />
      <Text style={styles.name}>{name}</Text>
      {description && <Text style={styles.description}>{description}</Text>}
    </View>
  );
}

const styles = StyleSheet.create({
  img: {
    borderRadius: 10,
    width: '100%',
    paddingTop: '100%',
    marginBottom: 10,
  },
  detailContainer: {
    width: '80%',
    height: 250,
    display: 'flex',
    flexDirection: 'column',
    alignItems: 'center',
    margin: 20,
    marginBottom: 60,
    cursor: 'pointer',
  },
  container: {
    width: 140,
    height: 140,
    display: 'flex',
    flexDirection: 'column',
    alignItems: 'center',
    margin: 20,
    marginBottom: 60,
    cursor: 'pointer',
  },
  name: {
    fontSize: 18,
    textAlign: 'center',
  },
  description: {
    textAlign: 'center',
    marginTop: 10,
    marginBottom: 10,
    color: '#ad7766',
    fontSize: 16,
  },
});

export default Product;
