# Slayer

Unreal Engine **5.8** の C++ ゲームプロジェクト。GAS（Gameplay Ability System）を軸にしたアクション系。

## プロジェクト構成

- **モジュール**: `Slayer`（Runtime, LoadingPhase: Default）
- **有効プラグイン**: `GameplayAbilities`(GAS), `ModelingToolsEditorMode`(Editorのみ), `AIAssistant`
- **依存モジュール** (`Source/Slayer/Slayer.Build.cs`)
  - Public: `Core`, `CoreUObject`, `Engine`, `InputCore`, `EnhancedInput`
  - Private: `GameplayAbilities`, `GameplayTasks`, `GameplayTags`
- 入力は **Enhanced Input** を使用（Input Mapping Context / Input Action）。

## ディレクトリ

- `Source/Slayer/Private/GameAbilitySystem/` — GAS関連のC++。キャラクターは `Character/` サブフォルダ。
- `Content/GenericShooter/GAS/Abilities/` — Gameplay Ability アセット（`GA_*`）。
- `Content/ParagonAurora/` — Epic配布の外部アセット（オーディオ/FX/メッシュ）。**編集対象ではない**。
- `Config/` — プロジェクト設定。`DefaultGameplayTags.ini` に Gameplay Tag を定義。

## コード規約

- クラス/変数のコメント・コミットメッセージは **日本語**。
- コミットメッセージは `[add]` `[fix]` `[update]` などのプレフィックス + 日本語要約。
- `TObjectPtr<T>` を使う（生ポインタではなく）。
- レベル名・Input Mapping Context 等の命名規則を守る（過去に命名規則違反の修正コミットあり）。

## GAS のパターン

`ATestCharacter`（`AbilitySystemInterface` 実装）が基本形:

- `UAbilitySystemComponent` を `CreateDefaultSubobject` で保持し、`SetIsReplicated(true)` + `SetReplicationMode(ReplicationMode)`。
- `ReplicationMode` はデフォルト `Mixed`（`EditAnywhere` で調整可）。過去に ReadOnly にしていた不具合あり、扱いに注意。
- `InitAbilityActorInfo(this, this)` を **`PossessedBy`（AI/敵用）と `OnRep_PlayerState`（プレイヤー用）の両方**で呼ぶ。マルチプレイ対応のため片方だけにしない。

## 作業上の注意

- **実装コードは本人が書く方針**。AIによるファイル変更はサマリー/コメント/typo修正に限定し、勝手にロジックを書き換えない。
- バグ相談時は、まず関連スクリプトを通読してから診断する。
- ビルドは Unreal Editor / Visual Studio（`Slayer.sln`）経由。`Intermediate/` `Saved/` `DerivedDataCache/` は生成物なので触らない。
