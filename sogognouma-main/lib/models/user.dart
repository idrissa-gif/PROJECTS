class User {
  final String firstName;
  final String lastName;
  final String email;
  final String phoneNumber;
  final String address;
  final DateTime dateOfBirth;
  final String gender;
  final String pin;
  User({
    required this.firstName,
    required this.lastName,
    required this.email,
    required this.phoneNumber,
    required this.address,
    required this.dateOfBirth,
    required this.gender,
    required this.pin,
  });

  factory User.fromJson(Map<String, dynamic> json) {
    return User(
      firstName: json['firstName'],
      lastName: json['lastName'],
      email: json['email'],
      phoneNumber: json['phoneNumber'],
      address: json['address'],
      dateOfBirth: DateTime.parse(json['dateOfBirth']),
      gender:  json['gender'],
      pin : json['pin']
    );
  }

  Map<String, dynamic> toJson() {
    return {
      'firstName': firstName,
      'lastName': lastName,
      'email': email,
      'phoneNumber': phoneNumber,
      'address': address,
      'dateOfBirth': dateOfBirth.toIso8601String(),
      'gender':gender,
      'pin':pin,
    };
  }
}
